#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.h"
#include "vec3_utils.h"
#include "ray.h"
#include "hit_record.h"

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
