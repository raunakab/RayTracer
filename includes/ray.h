#ifndef RAY_H
#define RAY_H

#include <vec3.h>
#include <vec3Utils.h>

class Ray {
private:
    Ray() = delete;

public:
    Vec3 A;
    Vec3 B;

    Ray(Vec3 const origin, Vec3 const direction);
    Ray(Ray const &);
    Ray(Ray const &&);
    ~Ray();

    void operator=(Ray const &);
    void operator=(Ray const &&);

    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 pointAtParameter(float const t0) const;
};

#endif
