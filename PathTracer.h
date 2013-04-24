#ifndef PATHTRACER_H
#define PATHTRACER_H

#include "Scene.h"
#include "Camera.h"
#include "Image.h"

class PathTracer {

    public:

        PathTracer(const unsigned int width, const unsigned int height, const unsigned int samples, Scene* scene);

        void generateImage(Image& image);


    private:

        static float rand01();

        static void getRandomHemisphereDir(Intersection& its, vec3& randDir, float& probDensity);

        static vec3 brdf(const Ray& outRay, Intersection& its, const Ray& inRay);


        const unsigned int width;
        const unsigned int height;
        const unsigned int samples;
        Scene* scene;
        vec3* image;
};

#endif // PATHTRACER_H
