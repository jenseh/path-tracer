#define GLM_SWIZZLE

#include "Triangle.h"

#include "Intersection.h"

Triangle::Triangle(const aiMesh* mesh, const unsigned int index, const mat4& transformation, Material* materials) {

    aiFace face = mesh->mFaces[index];
    vert0 = *(vec3*)&mesh->mVertices[face.mIndices[0]];
    vec3 vert1 = *(vec3*)&mesh->mVertices[face.mIndices[1]];
    vec3 vert2 = *(vec3*)&mesh->mVertices[face.mIndices[2]];
	
    vert0 = (transformation * vec4(vert0, 1.0f)).xyz();
    vert1 = (transformation * vec4(vert1, 1.0f)).xyz();
    vert2 = (transformation * vec4(vert2, 1.0f)).xyz();

    edge1 = vert1 - vert0;
    edge2 = vert2 - vert0;
	material = materials + mesh->mMaterialIndex;
}

inline bool Triangle::intersect(Ray& ray, Intersection& intersection) {

    vec3 pvec = cross(ray.direction, edge2);
    float det = dot(edge1, pvec);

    if(det <= 0.0)
        return false;

    vec3 tvec = ray.origin - vert0;

    float u = dot(tvec, pvec);

    if(u < 0.0f || u > det)
        return false;

    vec3 qvec = cross(tvec, edge1);

    float v = dot(ray.direction, qvec);

    if(v < 0.0f || u + v > det)
        return false;

    float t = dot(edge2, qvec);

    float inv_det = 1.0f / det;
    t *= inv_det;
    //u *= inv_det;
    //v *= inv_det;

    if(t >= intersection.getT())
        return false;

    intersection.set(t, ray.getPosition(t), cross(edge1, edge2), edge1, this);
    return true;
}

void Triangle::getAABB(vec3& lbf, vec3& rtn) {

	vec3 vert1 = vert0 + edge1;
	vec3 vert2 = vert0 + edge2;
    lbf = min(min(vert0, vert1), vert2);
    rtn = max(max(vert0, vert1), vert2);
}

vec3 Triangle::getCenter() {
    return vert0 + (edge1 + edge2) * 0.3333333f;
}

void Triangle::getRandomPos(vec3& position, vec3& normal, float& probability) {
	
	float x = (float) rand() / RAND_MAX;
	float y = (float) rand() / RAND_MAX;
	if(x + y > 1) {
		x = 1.0f - x;
		y = 1.0f - y;
	}
	position = vert0 + x * edge1 + y * edge2;
	normal = normalize(cross(edge1, edge2));
	probability = 2.0f / length(cross(edge1, edge2));
}
