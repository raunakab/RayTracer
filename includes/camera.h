#ifndef CAMERA_H
#define CAMERA_H

#include <ray.h>
#include <vec3.h>
#include <vec3Utils.h>
#include <math.h>

class Camera {
private:
    Camera() = delete;
    Camera(Camera const &) = delete;
    Camera(Camera const &&) = delete;
    void operator=(Camera const &) = delete;
    void operator=(Camera const &&) = delete;

public:
    Vec3 const w;
    Vec3 const u;
    Vec3 const v;
    float const halfHeight;
    float const halfWidth;
    Vec3 const origin;
    Vec3 const lowerLeftCorner;
    Vec3 const horizontal;
    Vec3 const vertical;
    float const lensRadius;

    Camera(Vec3 const &, Vec3 const &, Vec3 const &, float const, float const, float const, float const);
    ~Camera();

    Ray getRay(float const, float const) const;
};

#endif
