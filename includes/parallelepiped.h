#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vec3.h>
#include <hittableList.h>
#include <material.h>
#include <triangle.h>
#include <hittable.h>

class Parallelepiped : public Hittable {
private:
    Parallelepiped() = delete;
    Parallelepiped(Parallelepiped const &) = delete;
    Parallelepiped(Parallelepiped const &&) = delete;
    void operator=(Parallelepiped const &) = delete;
    void operator=(Parallelepiped const &&) = delete;

    Hittable ** determineHittableList() const;

public:
    int const meshCount;
    Vec3 const origin;
    Vec3 const basis0;
    Vec3 const basis1;
    Vec3 const basis2;
    Material const * const material;
    HittableList hittableList;

    Parallelepiped(Vec3 const &, Vec3 const &, Vec3 const &, Vec3 const &, Material const * const);
    ~Parallelepiped();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif
