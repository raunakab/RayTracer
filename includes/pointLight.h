#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <vec3.h>
#include <light.h>
#include <hitRecord.h>
#include <vec3Utils.h>

class PointLight : public Light {
private:
    PointLight() = delete;
    PointLight(PointLight const &) = delete;
    PointLight(PointLight const &&) = delete;

    void operator=(PointLight const &) = delete;
    void operator=(PointLight const &&) = delete;

public:
    PointLight(Vec3 const &, Vec3 const &, float const, float const, float const);
    ~PointLight();

    virtual float contribution(Hittable const * const, Vec3 const &) const;
};

#endif
