#include "Intersectable.h"

vec3 Intersectable::getEmission(const vec2& texturecoords) {
    return material->emission;
}

vec3 Intersectable::getDiffuse(const vec2& texturecoords) {
    return material->diffuse;
}

vec3 Intersectable::getSpecular() {
    return material->specular;
}

float Intersectable::getSpecularExponent() {
    return material->specularExponent;
}

bool Intersectable::isLightsource() {
	return material->emission != vec3(0.0f);
}