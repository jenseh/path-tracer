#ifndef SQUARE_H
#define SQUARE_H

#include "Intersectable.h"
#include "Material.h"


class Square : public Intersectable {

    public:

        Square(float size, const vec3& position, const vec3& normal, const vec3& tangent, Material* material);

        bool intersect(Ray& ray, Intersection& intersection);

        void getAABB(vec3& lbf, vec3& rtn);
        vec3 getCenter();
		
		void getRandomPos(vec3& position, vec3& normal, float& probability);


    private:

        float size;

        vec3 position;
        vec3 normal;
        vec3 tangent;
        vec3 bitangent;
};

#endif // SQUARE_H
