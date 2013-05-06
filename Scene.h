#ifndef SCENE_H
#define SCENE_H

#include "Ray.h"
#include "Intersection.h"
#include "Camera.h"
#include "AABB.h"
#include "Material.h"

class Scene {

    public:

        Scene(const int width, const int height);
        ~Scene();

        void addObject(Intersectable* object);
        void addAABB(AABB* aabb);
        void buildBVH();

        bool intersect(Ray& ray, Intersection& its);

        Ray generateCameraRay(const float x, const float y);

    private:

        Camera* camera;

        AABB rootNode;
};

#endif // SCENE_H
