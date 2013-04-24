#include "Square.h"

#include "Intersection.h"

Square::Square(float s, const vec3& p, const vec3& n, const vec3& t, const vec3& ke, const vec3& kd)
    : size(s), position(p), emission(ke), diffuse(kd) {

    normal = normalize(n);
    bitangent = normalize(cross(normal, t));
    tangent = cross(bitangent, normal);
}

bool Square::intersect(Ray& ray, Intersection& its) {

    float denom = dot(normal, ray.direction);
    if(denom >= 0.0f) return false;

    float t = dot(position - ray.origin, normal) / denom;

    if(t < its.getT() && t > 0.000001) {
        vec3 pos = ray.getPosition(t);

        if((abs(dot(pos - position, tangent)) > size/2)
        || (abs(dot(pos - position, bitangent)) > size/2))
            return false;

        its.set(t, pos, normal, tangent, this);

        return true;
    }
    return false;
}

vec3 Square::getEmission(Intersection* its) {

    return emission;
}

vec3 Square::getDiffuse(Intersection* its) {

    return diffuse;
}
