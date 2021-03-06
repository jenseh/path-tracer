#include "Square.h"

#include "Intersection.h"

Square::Square(float s, const vec3& p, const vec3& n, const vec3& t, Material* material)
    : size(s), position(p) {

	this->material = material;
		
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

        if((abs(dot(pos - position, tangent)) > size / 2)
        || (abs(dot(pos - position, bitangent)) > size / 2))
            return false;

        its.set(t, pos, normal, tangent, this);

        return true;
    }
    return false;
}

void Square::getAABB(vec3& lbf, vec3& rtn) {

    vec3 p = position + size / 2 * (tangent + bitangent);
    lbf = p; rtn = p;
    p = position + size / 2 * (tangent - bitangent);
    lbf = min(lbf, p); rtn = max(rtn, p);
    p = position - size / 2 * (tangent + bitangent);
    lbf = min(lbf, p); rtn = max(rtn, p);
    p = position - size / 2 * (tangent - bitangent);
    lbf = min(lbf, p); rtn = max(rtn, p);
}

vec3 Square::getCenter() {

    return position;
}

void Square::getRandomPos(vec3& position, vec3& normal, float& probability) {
	
	float x = size * 0.5f - size * (float) rand() / RAND_MAX;
	float y = size * 0.5f - size * (float) rand() / RAND_MAX;
	position = this->position + x * tangent + y * bitangent;
	normal = this->normal;
	probability = 1.0f / (size * size);
}
