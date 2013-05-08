#include "Intersectable.h"

vec3 Intersectable::getEmission(const vec2& texturecoords) {
    return material->emission;
}

vec3 Intersectable::getDiffuse(const vec2& texturecoords) {
    return material->diffuse;
}

bool Intersectable::isLightsource() {
	return material->emission != vec3(0.0f);
}