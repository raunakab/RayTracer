#ifndef METAL_H
#define METAL_H

#include <material.h>
#include <ray.h>
#include <vec3.h>
#include <vec3Utils.h>

class Metal : public Material {
private:
    Metal() = delete;
    Metal(Metal const &) = delete;
    Metal(Metal const &&) = delete;
    void operator=(Metal const &) = delete;
    void operator=(Metal const &&) = delete;

    float determineFuzz(float const fuzz) const;

public:
    Vec3 albedo;
    float const fuzz;

    Metal(Vec3 const &, float const);
    ~Metal();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const;
};

#endif
