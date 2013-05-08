#include "PathTracer.h"

#include "Ray.h"

PathTracer::PathTracer(const unsigned int width, const unsigned int height, const unsigned int samples, Scene* scene)
    : width(width), height(height), samples(samples), scene(scene) {

        scene->buildBVH();
}

void PathTracer::generateImage(Image& image) {

    for(unsigned int y = 0; y < height; y++) {
        printf("\rBild zu %3.0f%% berechnet.", 100.0 * y / height);fflush(stdout);
        #pragma omp parallel for
        for(unsigned int x = 0; x < width; x++) {
            vec3 pixel;
            for(unsigned int n = 0; n < samples; n++) {

                vec3 color = vec3(0.0f);        // akkumuliert die gewichteten Emissionsterme
                vec3 relevance = vec3(1.0f);    // akkumuliert die Gewichte

                Ray inRay = scene->generateCameraRay(rand01() - 0.5f + x, rand01() - 0.5f + y);

                float alpha = 1.0f;
                Intersection intersection;
				Intersection lightIntersection;
				if(scene->intersect(inRay, intersection)) {
					color += intersection.getEmission() * relevance;
					do {
						vec3 lightPos;
						vec3 lightNorm;
						vec3 lightColor;
						float lightProb;
						scene->getRandomLight(lightPos, lightNorm, lightColor, lightProb);
						vec3 lightDir = lightPos - intersection.getPosition();
						
						Ray lightRay(intersection.getPosition(), lightDir);
						float costhetai = dot(intersection.getNormal(), lightRay.direction);
						float costhetaj = -dot(lightNorm, lightRay.direction);
						
						if(costhetai >= 0 && costhetaj >= 0 
						&& !scene->intersect(lightRay, length(lightDir) * 0.9999)) {
							color += relevance
								* brdf(inRay, intersection, lightRay)
								* costhetai * costhetaj
								/ (lightProb * dot(lightDir, lightDir));
						}
						
						
						vec3 randDir;
						float probDensity;
						getRandomHemisphereDir(intersection, randDir, probDensity);
	
						Ray outRay(intersection.getPosition(), randDir);
	
						relevance *= brdf(inRay, intersection, outRay)
									* dot(intersection.getNormal(), outRay.direction)
									/ probDensity;
						
						alpha = min(1.0f, max(max(relevance.x, relevance.y), relevance.z)) * 0.9f;
						relevance /= alpha;
						
						inRay = outRay;
						intersection.reset();
					} while(rand01() <= alpha && scene->intersect(inRay, intersection));
				}
				
                color /= (float) samples;

                pixel += color;
            }
            image.setPixel(x, y, pixel);
        }
    }
}

inline float PathTracer::rand01() {
    return (float) rand() / RAND_MAX;
}

inline void PathTracer::getRandomHemisphereDir(Intersection& its, vec3& randDir, float& probDensity) {

    float theta = glm::acos(glm::sqrt(rand01()));
    float phi = 2.0f * M_PI * rand01();

    probDensity = glm::cos(theta) / M_PI;
    randDir = glm::cos(theta) * its.getNormal()
            + glm::sin(theta) * glm::cos(phi) * its.getTangent()
            + glm::sin(theta) * glm::sin(phi) * its.getBitangent();
}

inline vec3 PathTracer::brdf(const Ray& outRay, Intersection& its, const Ray& inRay) {

    return its.getDiffuse() / (float) M_PI;
}

