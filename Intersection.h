#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <cmath>

#include "Intersectable.h"

class Intersection {

    public:

        vec3 getPosition() const;
        vec3 getNormal() const;
        vec3 getTangent() const;
        vec3 getBitangent() const;

        vec3 getEmission() const;
        vec3 getDiffuse() const;
		vec3 getSpecular() const;
		float getSpecularExponent() const;

        float getT() const;

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
