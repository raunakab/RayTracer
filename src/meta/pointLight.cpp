#include <pointLight.h>

PointLight::PointLight(Vec3 const & lightPosition) : Light(lightPosition) {}
PointLight::~PointLight() {}

float PointLight::contribution(Hittable const * const hittable, Vec3 const & hitPoint) const {
    HitRecord record;
    float contribution(0.5);
    Ray lightRay(hitPoint, this->lightPosition - hitPoint);

    if (hittable->hit(lightRay, 0.001, MAXFLOAT, record)) contribution = 0.1;
    return contribution;
}
