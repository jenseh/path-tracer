#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Intersectable.h"

#include <assimp/aiMesh.h>

#include "Material.h"

class Triangle : public Intersectable {

    public:

        Triangle(const aiMesh* mesh, const unsigned int index, const mat4& transformation, Material* materials);

        bool intersect(Ray& ray, Intersection& intersection);

        void getAABB(vec3& lbf, vec3& rtn);
        vec3 getCenter();
		
		void getRandomPos(vec3& position, vec3& normal, float& probability);

    private:

        vec3 vert0;
        vec3 edge1;
        vec3 edge2;
};

#endif // TRIANGLE_H
