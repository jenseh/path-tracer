#ifndef SPHERE_H
#define SPHERE_H

#include "Intersectable.h"


class Sphere : public Intersectable {

    public:

        Sphere(float radius, const vec3& position, const vec3& ke, const vec3& kd);

        bool intersect(Ray& ray, Intersection& intersection);

        vec3 getEmission(Intersection* its);
        vec3 getDiffuse(Intersection* its);

    private:

        float radius;
        vec3 position;

        vec3 emission;
        vec3 diffuse;
};

#endif // SPHERE_H
