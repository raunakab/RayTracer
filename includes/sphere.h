#ifndef SPHERE_H
#define SPHERE_H

#include <vec3.h>
#include <hittable.h>
#include <ray.h>
#include <vec3Utils.h>
#include <material.h>

class Sphere : public Hittable {
private:
    Sphere() = delete;
    Sphere(Sphere const &) = delete;
    Sphere(Sphere const &&) = delete;
    void operator=(Sphere const &) = delete;
    void operator=(Sphere const &&) = delete;

public:
    Vec3 const centre;
    float const radius;
    Material const * const material;

    Sphere(Vec3 const &, float const, Material const * const);
    ~Sphere();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif
