#include <camera.h>

Camera::Camera(float const verticalThetaInDegrees, float const aspectRatio) :
halfHeight(tan(verticalThetaInDegrees / 2)),
halfWidth(aspectRatio * this->halfHeight),
origin(0.0,0.0,0.0),
lowerLeftCorner(-(this->halfWidth), -(this->halfHeight), -1.0),
horizontal(2*(this->halfWidth), 0.0, 0.0),
vertical(0.0, 2*(this->halfHeight), 0.0) {

}
Camera::~Camera() {}

Ray Camera::getRay(float const u, float const v) const {
    return Ray(this->origin, this->lowerLeftCorner + (u * this->horizontal) + (v * this->vertical));
}
