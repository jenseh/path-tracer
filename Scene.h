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
        bool intersect(Ray& ray, float t);

        Ray generateCameraRay(const float x, const float y);
		
		void getRandomLight(vec3& position, vec3& normal, vec3& color, float& probability);

    private:

        Camera* camera;

        AABB rootNode;
		
		std::vector<Intersectable*> lightsources;
};

#endif // SCENE_H
