#include "hit_record.h"

HitRecord::HitRecord() : t(0.0), p(0.0, 0.0, 0.0), normal(0.0, 0.0, 0.0) {}
HitRecord::HitRecord(float const t, Vec3 const & p, Vec3 const & normal) : t(t), p(p), normal(normal) {}
HitRecord::HitRecord(HitRecord const & other) : t(other.t), p(other.p), normal(other.normal) {}
HitRecord::HitRecord(HitRecord const && other) : t(other.t), p(other.p), normal(other.normal) {}
HitRecord::~HitRecord() {}

void HitRecord::operator=(HitRecord const & other) {
    this->t = other.t;
    this->p = other.p;
    this->normal = other.normal;

    return;
}
void HitRecord::operator=(HitRecord const && other) {
    this->t = other.t;
    this->p = other.p;
    this->normal = other.normal;

    return;
}
