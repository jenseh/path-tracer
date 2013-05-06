#ifndef AABB_H
#define AABB_H

#include "Intersectable.h"

#include <vector>

class AABB {

    public:

        void deleteTree();

        void addObject(Intersectable* object);
        void addAABB(AABB* child);
        void subdivide();

        bool intersect(Ray& ray, Intersection& intersection);

        void getAABB(vec3& lbf, vec3& rtn);
int count(){
	int result = objects.size();
	for(AABB* child : children) {
		result += child->count();
	}
	return result;
}
    private:

        vec3 lbf = vec3(INFINITY);
        vec3 rtn = vec3(-INFINITY);

        std::vector<Intersectable*> objects;
        std::vector<AABB*> children;

        bool intersect(Ray& ray);
};

#endif // AABB_H
