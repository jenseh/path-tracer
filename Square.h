#ifndef SQUARE_H
#define SQUARE_H

#include "Intersectable.h"


class Square : public Intersectable {

    public:

        Square(float size, const vec3& position, const vec3& normal, const vec3& tangent, const vec3& ke, const vec3& kd);

        bool intersect(Ray& ray, Intersection& intersection);

        vec3 getEmission(Intersection* its);
        vec3 getDiffuse(Intersection* its);


    private:

        float size;

        vec3 position;
        vec3 normal;
        vec3 tangent;
        vec3 bitangent;

        vec3 emission;
        vec3 diffuse;
};

#endif // SQUARE_H
