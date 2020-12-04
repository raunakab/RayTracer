#ifndef HIT_RECORD_H
#define HIT_RECORD_H

#include <vec3.h>
#include <vec3_utils.h>

struct HitRecord {
    float t;
    Vec3 p;
    Vec3 normal;

    HitRecord();
    HitRecord(float const, Vec3 const &, Vec3 const &);
    HitRecord(HitRecord const &);
    HitRecord(HitRecord const &&);
    ~HitRecord();

    void operator=(HitRecord const &);
    void operator=(HitRecord const &&);
};

#endif
