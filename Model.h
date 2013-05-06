#ifndef MODEL_H
#define MODEL_H

#include <assimp/assimp.hpp>
#include <assimp/aiScene.h>

#include "Scene.h"

class Model {

    public:

        Model(const char* filename);

        void addToScene(Scene* scene, const mat4& transformation);
        void addToScene(Scene* scene, const mat4& transformation, Material* material);

        AABB* createBVH(aiNode* node, const mat4& transformation, Material* material);

    private:

        Assimp::Importer importer;
        const aiScene* model;
};

#endif // MODEL_H
