#ifndef HITRECORD_H
#define HITRECORD_H

#include <vec3.h>
#include <vec3Utils.h>
#include <material.h>

class Material;

struct HitRecord {
    float t0;
    Vec3 hitPoint;
    Vec3 normal;
    Material const * material;

    HitRecord();
    HitRecord(float const, Vec3 const &, Vec3 const &, Material const * const);
    HitRecord(HitRecord const &);
    HitRecord(HitRecord const &&);
    ~HitRecord();

    void operator=(HitRecord const &);
    void operator=(HitRecord const &&);
};

#endif
