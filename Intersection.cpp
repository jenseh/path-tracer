#include "Intersection.h"

vec3 Intersection::getPosition() {

    return position;
}

vec3 Intersection::getNormal() {

    return normal;
}

vec3 Intersection::getTangent() {

    return tangent;
}

vec3 Intersection::getBitangent() {

    return bitangent;
}


vec3 Intersection::getEmission() {

    return object->getEmission(vec2());
}

vec3 Intersection::getDiffuse() {

    return object->getDiffuse(vec2());
}

float Intersection::getT() {

    return t;
}

void Intersection::set(float newT, vec3 pos, vec3 norm, vec3 tang, Intersectable* obj) {

    t = newT;
    position = pos;
    normal = normalize(norm);
    bitangent = normalize(cross(normal, tang));
    tangent = cross(bitangent, normal);
    object = obj;
}

void Intersection::reset() {

    t = INFINITY;
}
