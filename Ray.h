#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>
using namespace glm;

class Ray {

    public:

        Ray(const vec3& origin, const vec3& direction);

        vec3 getPosition(float t);

        vec3 origin;
        vec3 direction;
};

#endif // RAY_H
