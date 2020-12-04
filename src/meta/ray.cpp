#include <ray.h>

Ray::Ray(Vec3 const origin, Vec3 const direction) : A(origin), B(direction) {}
Ray::Ray(Ray const & other) : A(other.A), B(other.B) {}
Ray::Ray(Ray const && other) : A(other.A), B(other.B) {}
Ray::~Ray() {}

void Ray::operator=(Ray const & other) {

}
void Ray::operator=(Ray const && other) {
    this->A = other.A;
    this->B = other.B;
}

Vec3 Ray::origin() const { return this->A; }
Vec3 Ray::direction() const { return this->B; }
Vec3 Ray::pointAtParameter(float const t0) const { return this->A + (this->B * t0); }
