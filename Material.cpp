#include "Material.h"

Material::Material(const vec3& diffuse, const vec3& emission, const vec3& specular, const float specularExponent) 
	: diffuse(diffuse), emission(emission), specular(specular), specularExponent(specularExponent) {
}