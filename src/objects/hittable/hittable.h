#ifndef HITTABLE_H
#define HITTABLE_H

#include "../../meta/vec3/vec3.h"
#include "../../meta/vec3/vec3_utils.cpp"
#include "../../meta/ray/ray.h"
#include "../hit_record/hit_record.h"

class Hittable {
private:
    Hittable(Hittable const &) = delete;
    Hittable(Hittable const &&) = delete;
    void operator=(Hittable const &) = delete;
    void operator=(Hittable const &&) = delete;

public:
    Hittable();
    virtual ~Hittable();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const = 0;
};

#endif
