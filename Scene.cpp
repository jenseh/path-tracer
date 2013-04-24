#include "Scene.h"

#include "Sphere.h"
#include "Square.h"

Scene::Scene(const int width, const int height) {

    camera = new Camera(vec3(0.0f, 0.0f, 5.0f), vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f), width, height, 60.0f);

    addObject(new Sphere(0.5f, vec3(0.0f, -0.5f, 0.0f), vec3(0.0f), vec3(0.9f)));

    addObject(new Square(2.0f, vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, -1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f), vec3(0.9f)));
    addObject(new Square(2.0f, vec3(0.0f, -1.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f), vec3(0.9f)));
    addObject(new Square(2.0f, vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 0.0f, 1.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f), vec3(0.9f)));
    addObject(new Square(2.0f, vec3(1.0f, 0.0f, 0.0f), vec3(-1.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(0.0f), vec3(0.9f, 0.0f, 0.0f)));
    addObject(new Square(2.0f, vec3(-1.0f, 0.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(0.0f), vec3(0.0f, 0.9f, 0.0f)));

    addObject(new Square(1.0f, vec3(0.0f, 0.9f, 0.0f), vec3(0.0f, -1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec3(1.0f), vec3(0.0f)));
    addObject(new Square(1.0f, vec3(0.0f, 0.9f, 0.0f), vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), vec3(0.0f), vec3(0.0f)));

}

Scene::~Scene() {

    for(Intersectable* object : objects) {

        delete object;
    }
}

void Scene::addObject(Intersectable* object) {

    objects.push_back(object);
}

bool Scene::intersect(Ray& ray, Intersection& its) {

    bool result = false;
    for(Intersectable* object : objects) {
        if(object->intersect(ray, its)) {
            result = true;
        }
    }
    return result;
}

Ray Scene::generateCameraRay(const float x, const float y) {

    return camera->generateRay(x, y);
}
