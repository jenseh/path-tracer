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
		static float avg(const vec3& v);

        static vec3 getRandomCosineDir(const vec3& normal, const vec3& tangent, const vec3& bitangent, float exponent, float& probDensity);

		static const vec3 brdf(const Ray& inRay, const Intersection& its, const Ray& outRay);

        vec3 getLightSample(const Intersection& its, const vec3& relevance, const Ray& inRay);
		vec3 getPathSample(const Ray& inRay, const Intersection& its, Ray& outRay);

        const unsigned int width;
        const unsigned int height;
        const unsigned int samples;
        Scene* scene;
        vec3* image;
};

#endif // PATHTRACER_H
