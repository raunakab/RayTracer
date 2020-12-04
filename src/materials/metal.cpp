#include <metal.h>

Metal::Metal(Vec3 const & albedo, float const fuzz) : Material(), albedo(albedo), fuzz(this->determineFuzz(fuzz)) {}
Metal::~Metal() {}

float Metal::determineFuzz(float const fuzz) const {
    if (fuzz < 0.0) return 0.0;
    else if (fuzz > 1.0) return 1.0;
    return fuzz;
}

bool Metal::scatter(Ray const & rayIn, HitRecord const & record, Vec3 & attenuation, Ray & scattered) const {
    Vec3 const & hitPoint(record.hitPoint);
    Vec3 const & normal(record.normal);
    float const & fuzz(this->fuzz);

    Vec3 direction(rayIn.direction());
    direction.makeUnitVector();

    Vec3 reflectedPoint(0.0, 0.0, 0.0);
    reflect(direction, normal, reflectedPoint);
    scattered = Ray(hitPoint, reflectedPoint + (fuzz * randomUnitVector()));
    attenuation = this->albedo;

    return dot(scattered.direction(), normal) > 0.0;
}
