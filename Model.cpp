#include "Model.h"

#include <assimp/aiPostProcess.h>

#include "Triangle.h"

Model::Model(const char* filename) {

    model = importer.ReadFile(filename, aiProcess_Triangulate 
									  | aiProcess_PreTransformVertices 
									  | aiProcess_SortByPType  
									  | aiProcess_FindDegenerates 
									  | aiProcess_FindInvalidData);
    if(!model) {
        fprintf(stderr, "%s", importer.GetErrorString());
        printf("\nPress any Key to Terminate!");
        throw -1;
    }

}

void Model::addToScene(Scene* scene, const mat4& transformation) {

    scene->addAABB(createBVH(model->mRootNode, transformation, NULL));
}

void Model::addToScene(Scene* scene, const mat4& transformation, Material* material) {

    scene->addAABB(createBVH(model->mRootNode, transformation, material));
}

AABB* Model::createBVH(aiNode* node, const mat4& transformation, Material* material) {
	Material* materials;
	if(material != NULL) {
		materials = material;
	} else {
		materials = new Material[model->mNumMaterials];
		for(unsigned int i = 0; i < model->mNumMaterials; i++) {
			
			aiMaterial* mat = model->mMaterials[i];
			vec3 diffuse(1.0f);
			vec3 emission(0.0f);
			mat->Get(AI_MATKEY_COLOR_DIFFUSE, *(aiColor3D*)&diffuse);
			mat->Get(AI_MATKEY_COLOR_AMBIENT, *(aiColor3D*)&emission); // .obj besitzt keinen Emissionsparameter
			materials[i].diffuse = diffuse;
			materials[i].emission = emission;
		}
	}
	
    AABB* aabb = new AABB();

    for(unsigned int i = 0; i < node->mNumMeshes; i++) {

        aiMesh* mesh = model->mMeshes[node->mMeshes[i]];

		if(material != NULL) {
			mesh->mMaterialIndex = 0;
		}

        if(mesh->mPrimitiveTypes == aiPrimitiveType_TRIANGLE) {
            for(unsigned int j = 0; j < mesh->mNumFaces; j++) {

                aabb->addObject(new Triangle(mesh, j, transformation, materials));
            }
        }
    }
    for(unsigned int i = 0; i < node->mNumChildren; i++) {

        aabb->addAABB(createBVH(node->mChildren[i], transformation, material));
    }

    return aabb;
}
