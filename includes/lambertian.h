#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include <vec3.h>
#include <vec3Utils.h>
#include <blackbody.h>
#include <light.h>

class Lambertian : public BlackBody {
private:
    Lambertian() = delete;
    Lambertian(Lambertian const &) = delete;
    Lambertian(Lambertian const &&) = delete;

    void operator=(Lambertian const &) = delete;
    void operator=(Lambertian const &&) = delete;

public:
    Lambertian(Vec3 const &);
    ~Lambertian();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &, Light const * const) const;
};

#endif
