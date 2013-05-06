#include "AABB.h"

void AABB::deleteTree() {

    for(AABB* child : children) {
        child->deleteTree();
        delete child;
    }

    for(Intersectable* object : objects) {
        delete object;
    }
}

void AABB::addObject(Intersectable* object) {

    vec3 lbfO;
    vec3 rtnO;
    object->getAABB(lbfO, rtnO);
    lbf = min(lbf, lbfO);
    rtn = max(rtn, rtnO);

    objects.push_back(object);
}

void AABB::addAABB(AABB* child) {

    lbf = min(lbf, child->lbf);
    rtn = max(rtn, child->rtn);

    children.push_back(child);
}

void AABB::subdivide() {

    if(objects.size() > 4){
        std::vector<AABB*> newChildren;
        for(int i = 0; i < 8; i++) {
            newChildren.push_back(new AABB());
        }

        for(Intersectable* object : objects) {

            ivec3 i = mix(ivec3(1, 2, 4), ivec3(0), greaterThan((lbf + rtn) / 2.0f, object->getCenter()));

            newChildren[i.x + i.y + i.z]->addObject(object);
        }
        objects.clear();

        for(AABB* newChild : newChildren) {

            if(newChild->objects.size() < 2) {

                objects.insert(objects.begin(), newChild->objects.begin(), newChild->objects.end());
                delete newChild;

            } else {

                children.push_back(newChild);
            }
        }
        if(children.size() == 1 && objects.size() == 0) {

            objects = children[0]->objects;
            delete children[0];
            children.clear();
        }
    }
	
	for(AABB* child : children) {

		child->subdivide();
	}
}

bool AABB::intersect(Ray& ray) {

    float tnear = -INFINITY;
    float tfar = INFINITY;

    vec3 t1 = (lbf - ray.origin) * ray.inv_dir;
    vec3 t2 = (rtn - ray.origin) * ray.inv_dir;

    vec3 tmin = min(t1, t2);
    vec3 tmax = max(t1, t2);

    if(ray.direction.x != 0) {
        tnear = tmin.x;
        tfar  = tmax.x;
    }
    if(ray.direction.y != 0) {
        tnear = max(tnear, tmin.y);
        tfar  = min(tfar, tmax.y);
    }
    if(ray.direction.z != 0) {
        tnear = max(tnear, tmin.z);
        tfar  = min(tfar, tmax.z);
    }

    return tnear <= tfar && tfar >= 0.0f;
}


bool AABB::intersect(Ray& ray, Intersection& intersection) {

    if(!intersect(ray))
        return false;

    bool result = false;

    for(Intersectable* object : objects) {

        if(object->intersect(ray, intersection))
            result = true;
    }

    for(AABB* child : children) {

        if(child->intersect(ray, intersection))
            result = true;
    }
    return result;
}

void AABB::getAABB(vec3& lbf, vec3& rtn) {

    lbf = this->lbf;
    rtn = this->rtn;
}
