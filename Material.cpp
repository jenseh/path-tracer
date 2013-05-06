#include "Material.h"

Material::Material() 
	: diffuse(vec3(1.0f)), emission(vec3(0.0f)) {
}

Material::Material(const vec3& diffuse, const vec3& emission) 
	: diffuse(diffuse), emission(emission) {
}