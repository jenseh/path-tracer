#include "Scene.h"

#include "Sphere.h"
#include "Square.h"
#include "Model.h"

#include <glm/gtc/matrix_transform.hpp>


Scene::Scene(const int width, const int height) {
	
    camera = new Camera(vec3(0.0f, 0.0f, 5.0f), vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f), width, height, 60.0f);

    //addObject(new Sphere(0.2f, vec3(0.5f, 0.0f, 0.0f), new Material(vec3(1.0f, 0.0f, 1.0f), vec3(0.0f))));
	
	Model box("./data/Cornell-Box.obj");
    box.addToScene(this, mat4());
	
    Model bunny("./data/bun_zipper.ply");
    bunny.addToScene(this, 
					 scale(translate(mat4(), vec3(0.6f, -1.15f, 0.0f)), vec3(5.0f)),
					 new Material(vec3(0.9f), vec3(0.0f)));
					 
	Model dragon("./data/dragon_vrip.ply");
	dragon.addToScene(this,
					  scale(translate(mat4(), vec3(-0.5f, -1.25f, 0.0f)), vec3(-5.0f, 5.0f, -5.0f)),
					  new Material(vec3(0.9f), vec3(0.0f)));
	printf("%d Triangles\n", rootNode.count());
}

Scene::~Scene() {

    rootNode.deleteTree();
    delete camera;
}

void Scene::addObject(Intersectable* object) {

    rootNode.addObject(object);
}

void Scene::addAABB(AABB* aabb) {

    rootNode.addAABB(aabb);
}

void Scene::buildBVH() {

    rootNode.subdivide();
}

bool Scene::intersect(Ray& ray, Intersection& its) {

    return rootNode.intersect(ray, its);
}

Ray Scene::generateCameraRay(const float x, const float y) {

    return camera->generateRay(x, y);
}
