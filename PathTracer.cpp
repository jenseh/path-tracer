#include "PathTracer.h"

#include "Ray.h"

PathTracer::PathTracer(const unsigned int width, const unsigned int height, Scene* scene)
    : width(width), height(height), scene(scene) {

        scene->buildBVH();
}

void PathTracer::generateImage(Image& image, const unsigned int samples) {

    for(unsigned int n = 0; n < samples; n++) {
        printf("\rBild zu %3.0f%% berechnet.", 100.0 * n / samples);fflush(stdout);
		refineImage(image, n);
    }
}

void PathTracer::refineImage(Image& image, const unsigned int n) {
	#pragma omp parallel for collapse(2)
	for(unsigned int y = 0; y < height; y++) {
		for(unsigned int x = 0; x < width; x++) {
            
			vec3 color = vec3(0.0f);        // akkumuliert die gewichteten Emissionsterme
			vec3 relevance = vec3(1.0f);    // akkumuliert die Gewichte

			Ray currRay = scene->generateCameraRay(rand01() - 0.5f + x, rand01() - 0.5f + y);

			float alpha = 1.0f;
			Intersection intersection;
			Intersection lightIntersection;
			if(scene->intersect(currRay, intersection)) {
				color += intersection.getEmission();
				do {
					color += getLightSample(intersection, relevance, currRay);
					
					Ray nextRay;
					relevance *= getPathSample(currRay, intersection, nextRay);
					
					alpha = min(1.0f, max(max(relevance.x, relevance.y), relevance.z)) * 0.9f;
					relevance /= alpha;
					
					currRay = nextRay;
					intersection.reset();
				} while(rand01() <= alpha && scene->intersect(currRay, intersection));
			}
		image.setPixel(x, y, ((float) n * image.getPixel(x, y) + min(vec3(10.0f), color)) / (n + 1.0f));
		}
	}
}

vec3 PathTracer::getLightSample(const Intersection& its, const vec3& relevance, const Ray& inRay) {
	vec3 lightPos;
	vec3 lightNorm;
	vec3 lightColor;
	float lightProb;
	scene->getRandomLight(lightPos, lightNorm, lightColor, lightProb);
	vec3 lightDir = lightPos - its.getPosition();
						
	Ray lightRay(its.getPosition(), lightDir);
	float costhetai = dot(its.getNormal(), lightRay.direction);
	float costhetaj = -dot(lightNorm, lightRay.direction);
						
	if(costhetai >= 0 && costhetaj >= 0 && !scene->intersect(lightRay, length(lightDir) * 0.99999f)) {
		return lightColor * relevance
				* brdf(inRay, its, lightRay)
				* costhetai * costhetaj
				/ (lightProb * dot(lightDir, lightDir));
	} else {
		return vec3(0.0f);
	}
}

vec3 PathTracer::getPathSample(const Ray& inRay, const Intersection& its, Ray& outRay) {
	
	float probDensity;
	
	vec3 kd = its.getDiffuse();
	vec3 ks = its.getSpecular();
	
	float xi = rand01() * avg(kd + ks);
	xi -= avg(kd);
	if(xi < 0.0f) {
		vec3 pathDir = getRandomCosineDir(its.getNormal(), its.getTangent(), its.getBitangent(), 1, probDensity);
		outRay = Ray(its.getPosition(), pathDir);
	} else {
		vec3 reflectDir = reflect(inRay.direction, its.getNormal());
		vec3 tangent = cross(reflectDir, its.getNormal());
		if(length(tangent) == 0.0f)
			tangent = its.getTangent();
		tangent = normalize(tangent);
		vec3 bitangent = cross(reflectDir, tangent);
		vec3 pathDir = getRandomCosineDir(reflectDir, tangent, bitangent, its.getSpecularExponent(), probDensity);
		outRay = Ray(its.getPosition(), pathDir);
		if(0.0f >= dot(its.getNormal(), pathDir))
			return vec3(0.0f);
	}
	return brdf(inRay, its, outRay) * dot(its.getNormal(), outRay.direction) / (probDensity);
}

inline const vec3 PathTracer::brdf(const Ray& inRay, const Intersection& its, const Ray& outRay) {
	
	vec3 kd = its.getDiffuse();
	vec3 ks = its.getSpecular();
	float ns = its.getSpecularExponent();
	
	vec3 reflectDir = reflect(inRay.direction, its.getNormal());
	
	return kd * (float) M_1_PI
		 + ks * (ns * 0.5f + 1.0f) * (float) M_1_PI * pow(dot(reflectDir, outRay.direction), ns);
}

inline float PathTracer::avg(const vec3& v) {
	return (v.x + v.y + v.z) / 3.0f;
}

inline float PathTracer::rand01() {
    return (float) rand() / RAND_MAX;
}

inline vec3 PathTracer::getRandomCosineDir(const vec3& normal, const vec3& tangent, const vec3& bitangent, float exponent, float& probDensity) {
	
	float theta = acos(pow(rand01(), 1.0f / (exponent + 1.0f)));
    float phi = 2.0f * M_PI * rand01();

    probDensity = (0.5f * exponent + 0.5f) * M_1_PI * pow(cos(theta), exponent);
    return cos(theta) * normal
		 + sin(theta) * cos(phi) * tangent
		 + sin(theta) * sin(phi) * bitangent;
}

