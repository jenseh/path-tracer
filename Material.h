#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
using namespace glm;

class Material {
	
public:
		Material();
		Material(const vec3& diffuse, const vec3& emission);
		
		vec3 diffuse;
		vec3 emission;
};

#endif //MATERIAL_H
