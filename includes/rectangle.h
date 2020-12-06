#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vec3.h>
#include <hittableList.h>
#include <material.h>
#include <triangle.h>
#include <hittable.h>

class Rectangle : public Hittable {
private:
    Rectangle() = delete;
    Rectangle(Rectangle const &) = delete;
    Rectangle(Rectangle const &&) = delete;
    void operator=(Rectangle const &) = delete;
    void operator=(Rectangle const &&) = delete;

    Hittable ** determineHittableList() const;

public:
    int const meshCount;
    Vec3 const origin;
    Vec3 const basis0;
    Vec3 const basis1;
    Vec3 const basis2;
    Material const * const material;
    HittableList hittableList;

    Rectangle(Vec3 const &, Vec3 const &, Vec3 const &, Vec3 const &, Material const * const);
    ~Rectangle();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif
