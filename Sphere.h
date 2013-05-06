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

        vec3 getEmission(Intersection* its);
        vec3 getDiffuse(Intersection* its);

    private:

        float radius;
        vec3 position;

        Material* material;
};

#endif // SPHERE_H
