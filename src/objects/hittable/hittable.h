#ifndef HITTABLE_H
#define HITTABLE_H

#include "../../vec3/vec3.h"
#include "../../vec3/vec3_utils.cpp"
#include "../../ray/ray.h"

struct HitRecord {
    float t;
    Vec3 p;
    Vec3 normal;
};

class Hittable {
private:
    Hittable(Hittable const &) = delete;
    Hittable(Hittable const &&) = delete;
    void operator=(Hittable const &) = delete;
    void operator=(Hittable const &&) = delete;

public:
    Hittable();
    ~Hittable();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const = 0;
};

#endif
