#include "Image.h"

#include <OpenEXR/ImfRgbaFile.h>
using namespace Imf;

Image::Image(const unsigned int width, const unsigned int height)
    : width(width), height(height) {

    pixels = new vec3[width * height];
}

Image::~Image() {

    delete[] pixels;
}

void Image::setPixel(const unsigned int x, const unsigned int y, const vec3& pixel) {

    pixels[x + y * width] = pixel;
}

void Image::saveToFile(const char* filename) {

    Rgba ps[width * height];
    for(unsigned int y = 0; y < height; y++) {
        for(unsigned int x = 0; x < width; x++) {
            int i = x + y * width;
            int j = x + (height - y - 1) * width;
            ps[j] = Rgba(pixels[i].r, pixels[i].g, pixels[i].b, 1.0f);
        }
    }


    RgbaOutputFile file(filename, width, height, WRITE_RGBA);
    file.setFrameBuffer(ps, 1, width);
    file.writePixels(height);
}
