#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vec3.h>
#include <hittable.h>
#include <material.h>
#include <vec3Utils.h>

class Triangle : public Hittable {
private:
    Triangle() = delete;
    Triangle(Triangle const &) = delete;
    Triangle(Triangle const &&) = delete;
    void operator=(Triangle const &) = delete;
    void operator=(Triangle const &&) = delete;

public:
    Vec3 const a;
    Vec3 const b;
    Vec3 const c;
    Vec3 const nonUnitNormal;
    Material const * const material;

    Triangle(Vec3 const &, Vec3 const &, Vec3 const &, Material const * const);
    ~Triangle();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif
