#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <cmath>

#include <glm/glm.hpp>
using namespace glm;

#include "Intersectable.h"

class Intersection {

    public:

        vec3 getPosition();
        vec3 getNormal();
        vec3 getTangent();
        vec3 getBitangent();

        vec3 getEmission();
        vec3 getDiffuse();

        float getT();

        void set(float t, vec3 position = vec3(), vec3 normal = vec3(), vec3 tangent = vec3(), Intersectable* object = NULL);
        void reset();

    private:

        float t = INFINITY;

        vec3 position;
        vec3 normal;
        vec3 tangent;
        vec3 bitangent;

        Intersectable* object;
};

#endif // INTERSECTION_H
