#include "Ray.h"

Ray::Ray(const vec3& o, const vec3& d)
    : origin(o), direction(normalize(d)), inv_dir(vec3(1.0f) / direction) {
}

vec3 Ray::getPosition(float t) {

    return origin + t * direction;
}
