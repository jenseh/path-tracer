#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include <glm/glm.hpp>
using namespace glm;

#include "Ray.h"
#include "Material.h"

class Intersection;

class Intersectable
{
    public:

        virtual ~Intersectable() {}

        virtual bool intersect(Ray& ray, Intersection& intersection) = 0;

        virtual void getAABB(vec3& lbf, vec3& rtn) = 0;
        virtual vec3 getCenter() = 0;

		virtual void getRandomPos(vec3& position, vec3& normal, float& probability) = 0;

        virtual vec3 getEmission(const vec2& texturecoords);
        virtual vec3 getDiffuse(const vec2& texturecoords);
		
		virtual bool isLightsource();
	
	protected:
		
		Material* material;
};

#endif // INTERSECTABLE_H
