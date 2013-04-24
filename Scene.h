#ifndef SCENE_H
#define SCENE_H

#include <vector>
using namespace std;

#include "Ray.h"
#include "Intersection.h"
#include "Camera.h"

class Scene {

    public:

        Scene(const int width, const int height);
        ~Scene();

        void addObject(Intersectable* object);

        bool intersect(Ray& ray, Intersection& its);

        Ray generateCameraRay(const float x, const float y);

    private:

        vector<Intersectable*> objects;
        Camera* camera;
};

#endif // SCENE_H
