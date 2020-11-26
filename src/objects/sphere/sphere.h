#ifndef SPHERE_H
#define SPHERE_H

#include "../../meta/vec3/vec3.h"
#include "../hittable/hittable.h"
#include "../../meta/ray/ray.h"
#include "../../meta/vec3/vec3_utils.cpp"

class Sphere : public Hittable {
private:
    Sphere() = delete;
    Sphere(Sphere const &) = delete;
    Sphere(Sphere const &&) = delete;
    void operator=(Sphere const &) = delete;
    void operator=(Sphere const &&) = delete;

public:
    Vec3 const center;
    float const radius;

    Sphere(Vec3 const &, float const);
    ~Sphere();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif
