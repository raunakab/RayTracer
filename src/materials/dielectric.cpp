#include <dielectric.h>

Dielectric::Dielectric(float const refractionIndex) : refractionIndex(refractionIndex) {}
Dielectric::~Dielectric() {}

bool Dielectric::scatter(Ray const & rayIn, HitRecord const & record, Vec3 & attenuation, Ray & scattered, Light const * const light) const {
    Vec3 outwardNormal(0.0, 0.0, 0.0);
    Vec3 reflected(0.0, 0.0, 0.0);
    Vec3 refracted(0.0, 0.0, 0.0);
    float const & refractionIndex(this->refractionIndex);

    Vec3 const & recordNormal(record.normal);
    Vec3 const & recordHitPoint(record.hitPoint);
    Vec3 rayDirection(rayIn.direction());

    float reflectionProbability;
    float cosine;

    attenuation = Vec3(1.0, 1.0, 1.0);

    reflect(rayDirection, recordNormal, reflected);

    float niOverNt;
    if (dot(rayDirection, recordNormal) > 0.0) {
        outwardNormal = -recordNormal;
        niOverNt = refractionIndex;
        cosine = (refractionIndex / rayDirection.length()) * dot(rayDirection, recordNormal);
    } else {
        outwardNormal = recordNormal;
        niOverNt = 1.0 / refractionIndex;
        cosine = (-1.0 / rayDirection.length()) * dot(rayDirection, recordNormal);
    }

    if (refract(rayDirection, outwardNormal, niOverNt, refracted)) {
        reflectionProbability = schlick(cosine, refractionIndex);
    } else {
        scattered = Ray(recordHitPoint, reflected);
        reflectionProbability = 1.0;
    }

    if (drand48() < reflectionProbability) scattered = Ray(recordHitPoint, reflected);
    else scattered = Ray(recordHitPoint, refracted);

    return true;
}
