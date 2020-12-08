#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include <vec3.h>
#include <light.h>
#include <hitRecord.h>
#include <vec3Utils.h>

class DirectionalLight : public Light {
private:
    DirectionalLight() = delete;
    DirectionalLight(DirectionalLight const &) = delete;
    DirectionalLight(DirectionalLight const &&) = delete;

    void operator=(DirectionalLight const &) = delete;
    void operator=(DirectionalLight const &&) = delete;

public:
    DirectionalLight(Vec3 const &, Vec3 const &, float const, float const, float const);
    ~DirectionalLight();

    virtual float contribution(Hittable const * const, Vec3 const &) const;
};

#endif
