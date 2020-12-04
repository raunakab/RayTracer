#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <vec3.h>
#include <material.h>
#include <vec3Utils.h>

class Lambertian : public Material {
private:
    Lambertian() = delete;
    Lambertian(Lambertian const &) = delete;
    Lambertian(Lambertian const &&) = delete;

    void operator=(Lambertian const &) = delete;
    void operator=(Lambertian const &&) = delete;

public:
    Vec3 const albedo;

    Lambertian(Vec3 const &);
    ~Lambertian();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const;
};

#endif
