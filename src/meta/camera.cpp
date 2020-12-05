#include <camera.h>

Camera::Camera(Vec3 const & lookFrom, Vec3 const & lookAt, Vec3 const & vUp, float const verticalThetaInDegrees, float const aspectRatio, float const aperture, float const focusDistance) :
// w(lookFrom - lookAt),
// u(unitVector(cross(vUp, this->w))),
// v(unitVector(cross(this->w, this->u))),
// origin(lookFrom),
w(unitVector(lookFrom - lookAt)),
u(unitVector(cross(vUp, this->w))),
v(cross(this->w, this->u)),
halfHeight(tan(verticalThetaInDegrees / 2)),
halfWidth(aspectRatio * halfHeight),
origin(lookFrom),
lowerLeftCorner(this->origin - (focusDistance * ((this->halfWidth * this->u) + (this->halfHeight * this->v) + this->w))),
horizontal((2 * focusDistance * this->halfWidth) * this->u),
vertical((2 * focusDistance * this->halfHeight) * this->v),
lensRadius(aperture / 2) {}
Camera::~Camera() {}

Ray Camera::getRay(float const s, float const t) const {
    Vec3 rd(this->lensRadius * randomInUnitDisk());
    Vec3 offset((this->u * rd.x()) + (this->v * rd.y()) + this->origin);
    return Ray(offset, this->lowerLeftCorner + (s * this->horizontal) + (t * this->vertical) - offset);
}
