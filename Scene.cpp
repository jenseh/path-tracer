#include "Scene.h"

#include "Sphere.h"
#include "Square.h"
#include "Model.h"

#include <glm/gtc/matrix_transform.hpp>


Scene::Scene(const int width, const int height) {
	
    camera = new Camera(vec3(0.0f, 0.0f, 5.0f), vec3(0.0f, 0.0f, -1.0f), vec3(0.0f, 1.0f, 0.0f), width, height, 60.0f);

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
	if(object->isLightsource()) {
		lightsources.push_back(object);
	}
}

void Scene::addAABB(AABB* aabb) {
	aabb->getLightsources(lightsources);
    rootNode.addAABB(aabb);
}

void Scene::buildBVH() {

    rootNode.subdivide();
}

bool Scene::intersect(Ray& ray, Intersection& its) {

    return rootNode.intersect(ray, its);
}

bool Scene::intersect(Ray& ray, float t) {
	return rootNode.intersect(ray, t);
}

Ray Scene::generateCameraRay(const float x, const float y) {

    return camera->generateRay(x, y);
}

void Scene::getRandomLight(vec3& position, vec3& normal, vec3& color, float& probability) {

	int index = rand() % lightsources.size();
	lightsources[index]->getRandomPos(position, normal, probability);
	probability /= lightsources.size();
	color = lightsources[index]->getEmission(vec2());
}
