#ifndef RAY_H
#define RAY_H

#include <vec3.h>
#include <vec3_utils.h>

class Ray {
private:
    Ray() = delete;
    void operator=(Ray const &) = delete;
    void operator=(Ray const &&) = delete;

public:
    Vec3 const A;
    Vec3 const B;

    Ray(Vec3 const origin, Vec3 const direction);
    Ray(Ray const &);
    Ray(Ray const &&);
    ~Ray();

    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 pointAtParameter(float const t) const;
};

#endif
