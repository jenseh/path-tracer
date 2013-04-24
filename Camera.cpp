#include "Camera.h"

Camera::Camera(const vec3& pos, const vec3& dir, const vec3& up, const int width, const int height, const float fieldOfView)
    : position(pos) {

    deltaX = normalize(cross(dir, up))     * (float)tan(radians(0.5 * fieldOfView)) / (float) height;
    deltaY = normalize(cross(deltaX, dir)) * (float)tan(radians(0.5 * fieldOfView)) / (float) height;
    direction = normalize(dir)
                + (1.0f - width) * 0.5f * deltaX
                + (1.0f - height) * 0.5f * deltaY;
}

Ray Camera::generateRay(const float x, const float y) {

    return Ray(position, normalize(direction + x * deltaX + y * deltaY));
}
