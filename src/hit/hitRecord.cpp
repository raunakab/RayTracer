#include <hitRecord.h>

HitRecord::HitRecord() : t0(0.0), hitPoint(0.0, 0.0, 0.0), normal(0.0, 0.0, 0.0) {}
HitRecord::HitRecord(float const t0, Vec3 const & hitPoint, Vec3 const & normal, Material const * const material) :
t0(t0),
hitPoint(hitPoint),
normal(normal),
material(material) {}
HitRecord::HitRecord(HitRecord const & other) : t0(other.t0), hitPoint(other.hitPoint), normal(other.normal), material(other.material) {}
HitRecord::HitRecord(HitRecord const && other) : t0(other.t0), hitPoint(other.hitPoint), normal(other.normal), material(other.material) {}
HitRecord::~HitRecord() {}

void HitRecord::operator=(HitRecord const & other) {
    this->t0 = other.t0;
    this->hitPoint = other.hitPoint;
    this->normal = other.normal;
    this->material = other.material;

    return;
}
void HitRecord::operator=(HitRecord const && other) {
    this->t0 = other.t0;
    this->hitPoint = other.hitPoint;
    this->normal = other.normal;
    this->material = other.material;

    return;
}
