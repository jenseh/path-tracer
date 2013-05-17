#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
using namespace glm;

class Material {
	
public:
		Material(const vec3& diffuse = vec3(1.0f), 
				 const vec3& emission = vec3(0.0f), 
				 const vec3& specular = vec3(0.0f), 
				 const float specularExponent = 1.0f);
		
		vec3 diffuse;
		vec3 emission;
		vec3 specular;
		float specularExponent;
};

#endif //MATERIAL_H
