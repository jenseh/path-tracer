#include "Intersection.h"

vec3 Intersection::getPosition() const {

    return position;
}

vec3 Intersection::getNormal() const {

    return normal;
}

vec3 Intersection::getTangent() const {

    return tangent;
}

vec3 Intersection::getBitangent() const {

    return bitangent;
}


vec3 Intersection::getEmission() const {

    return object->getEmission(vec2());
}

vec3 Intersection::getDiffuse() const {

    return object->getDiffuse(vec2());
}

vec3 Intersection::getSpecular() const {

    return object->getSpecular();
}

float Intersection::getSpecularExponent() const {

    return object->getSpecularExponent();
}

float Intersection::getT() const {

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
