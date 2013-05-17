#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>
using namespace glm;

class Ray {

    public:

        Ray(const vec3& origin = vec3(), const vec3& direction = vec3(0.0f, 0.0f, -1.0f));

        vec3 getPosition(float t);

        vec3 origin;
        vec3 direction;
        vec3 inv_dir;
};

#endif // RAY_H
