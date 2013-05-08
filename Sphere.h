#ifndef SPHERE_H
#define SPHERE_H

#include "Intersectable.h"
#include "Material.h"

class Sphere : public Intersectable {

    public:

        Sphere(float radius, const vec3& position, Material* material);

        bool intersect(Ray& ray, Intersection& intersection);

        void getAABB(vec3& lbf, vec3& rtn);
        vec3 getCenter();
		
		void getRandomPos(vec3& position, vec3& normal, float& probability);

    private:

        float radius;
        vec3 position;
};

#endif // SPHERE_H
