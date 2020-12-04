#ifndef MATERIAL_H
#define MATERIAL_H

#include <ray.h>
#include <hitRecord.h>
#include <vec3.h>

class HitRecord;

class Material {
private:
    Material(Material const &) = delete;
    Material(Material const &&) = delete;
    void operator=(Material const &) = delete;
    void operator=(Material const &&) = delete;

public:
    Material();
    virtual ~Material();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const = 0;
};

#endif
