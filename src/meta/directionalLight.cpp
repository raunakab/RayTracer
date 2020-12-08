#include <directionalLight.h>

DirectionalLight::DirectionalLight(Vec3 const & lightColour, Vec3 const & lightPosition, float const lightContribution, float const shadowContribution, float const lightFuzz) :
Light(lightColour, lightPosition, lightContribution, shadowContribution, lightFuzz)
{}
DirectionalLight::~DirectionalLight() {}

float DirectionalLight::contribution(Hittable const * const hittable, Vec3 const & hitPoint) const {
    HitRecord record;
    Ray lightRay(hitPoint, this->lightPosition + (this->lightFuzz * randomUnitVector()));

    if (hittable->hit(lightRay, 0.001, MAXFLOAT, record)) return this->shadowContribution;
    return this->lightContribution;
}
