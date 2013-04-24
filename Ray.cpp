#include "Ray.h"

Ray::Ray(const vec3& o, const vec3& d) : origin(o), direction(normalize(d)) {}

vec3 Ray::getPosition(float t) {

    return origin + t * direction;
}
