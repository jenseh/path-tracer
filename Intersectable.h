#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include <glm/glm.hpp>
using namespace glm;

#include "Ray.h"

class Intersection;

class Intersectable
{
    public:

        virtual ~Intersectable() {}

        virtual bool intersect(Ray& ray, Intersection& intersection) = 0;

        virtual vec3 getEmission(Intersection* its) = 0;
        virtual vec3 getDiffuse(Intersection* its) = 0;
};

#endif // INTERSECTABLE_H
