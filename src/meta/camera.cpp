#include <camera.h>

Camera::Camera() :
origin(0.0,0.0,0.0),
lowerLeftCorner(-2.0, -1.0, -1.0),
horizontal(4.0, 0.0, 0.0),
vertical(0.0, 2.0, 0.0) {}
Camera::~Camera() {}

Ray Camera::getRay(float const u, float const v) const {
    return Ray(this->origin, this->lowerLeftCorner + (u * this->horizontal) + (v * this->vertical));
}
