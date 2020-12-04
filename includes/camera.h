#ifndef CAMERA_H
#define CAMERA_H

#include <ray.h>

class Camera {
private:
    Camera(Camera const &) = delete;
    Camera(Camera const &&) = delete;
    void operator=(Camera const &) = delete;
    void operator=(Camera const &&) = delete;

public:
    Camera();
    ~Camera();

    Ray getRay(int const, int const) const;
};

#endif
