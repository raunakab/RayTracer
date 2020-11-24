#include "ray.h"

ray::ray(vec3 const origin, vec3 const direction) : A(origin), B(direction) {}
ray::ray(ray const & other) : A(other.A), B(other.B) {}
ray::ray(ray const && other) : A(other.A), B(other.B) {}
ray::~ray() {}

vec3 ray::origin() const { return this->A; }
vec3 ray::direction() const { return this->B; }
