#include "Sphere.h"

#include "Intersection.h"

Sphere::Sphere(float r, const vec3& pos, Material* material)
    : radius(r), position(pos), material(material) {}

bool Sphere::intersect(Ray& ray, Intersection& its) {

    float A = dot(ray.direction, ray.direction);
    float B = 2.0f * dot(ray.origin - position, ray.direction);
    float C = dot(ray.origin - position, ray.origin - position) - radius * radius;
    float disc = B * B - 4.0f * A * C;
    if(disc < 0) return false;
    float t = (B + sqrt(disc)) / -2.0f * A;
    if(t < its.getT() && t > 0.000001) {
        vec3 pos = ray.getPosition(t);
        vec3 relPos = pos - position;
        vec3 tangent = cross(relPos, vec3(1.0f, 0.0f, 0.0f));
        if(dot(tangent, tangent) < 0.25f)
            tangent = cross(relPos, vec3(0.0f, 1.0f, 0.0f));
        its.set(t, pos, relPos, tangent, this);

        return true;
    }
    return false;
}

void Sphere::getAABB(vec3& lbf, vec3& rtn) {

    lbf = position - vec3(radius);
    rtn = position + vec3(radius);
}

vec3 Sphere::getCenter() {

    return position;
}

vec3 Sphere::getEmission(Intersection* its) {

    return material->emission;
}

vec3 Sphere::getDiffuse(Intersection* its) {

    return material->diffuse;
}
