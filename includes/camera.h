#ifndef CAMERA_H
#define CAMERA_H

#include <ray.h>
#include <vec3_utils.h>

class Camera {
private:
    Camera(Camera const &) = delete;
    Camera(Camera const &&) = delete;
    void operator=(Camera const &) = delete;
    void operator=(Camera const &&) = delete;

public:
    Vec3 origin;
    Vec3 lowerLeftCorner;
    Vec3 horizontal;
    Vec3 vertical;

    Camera();
    ~Camera();

    Ray getRay(float const, float const) const;
};

#endif
