#ifndef IMAGE_H
#define IMAGE_H

#include <glm/glm.hpp>
using namespace glm;

class Image {

    public:

        Image(const unsigned int width, const unsigned int height);
        ~Image();

        void setPixel(const unsigned int x, const unsigned int y, const vec3& pixel);

        void saveToFile(const char* filename);

    private:

        const unsigned int width;
        const unsigned int height;
        vec3* pixels;
};

#endif // IMAGE_H
