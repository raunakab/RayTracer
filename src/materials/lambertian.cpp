#include <lambertian.h>

Lambertian::Lambertian(Vec3 const & albedo) : BlackBody(albedo) {}
Lambertian::~Lambertian() {}

bool Lambertian::scatter(Ray const & rayIn, HitRecord const & record, Vec3 & attenuation, Ray & scattered) const {
    Vec3 target(record.hitPoint + record.normal);
    scattered = Ray(record.hitPoint, record.normal + randomUnitVector());
    attenuation = this->albedo;

    return true;
}
