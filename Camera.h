#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.h"

class Camera {

    public:

        Camera(const vec3& pos, const vec3& dir, const vec3& up, const int width, const int height, const float fieldOfView);

        Ray generateRay(const float x, const float y);


    private:

        vec3 position;
        vec3 direction;
        vec3 deltaX;
        vec3 deltaY;

};

#endif // CAMERA_H
