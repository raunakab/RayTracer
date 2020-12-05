#include <vec3Utils.h>

Vec3 randomUnitVector() {
    Vec3 const displacement(1.0, 1.0, 1.0);
    Vec3 point(0.0, 0.0, 0.0);

    do {
        point = (2 * Vec3(drand48(), drand48(), drand48())) - displacement;
    } while (point.squaredLength() >= 1.0);

    return point;
}
Vec3 randomInUnitDisk() {
    Vec3 const displacement(1.0, 1.0, 0.0);
    Vec3 point(0.0, 0.0, 0.0);

    do {
        point = (2 * Vec3(drand48(), drand48(), 0.0)) - displacement;
    } while (point.squaredLength() >= 1.0);

    return point;
}
void reflect(Vec3 const & v, Vec3 const & normal, Vec3 & resultDestination) {
    resultDestination = v - ((2 * dot(v, normal)) * normal);
}
bool refract(Vec3 const & v, Vec3 const & normal, float const niOverNt, Vec3 & resultDestination) {
    Vec3 unitV(unitVector(v));
    float const dt(dot(unitV, normal));
    float discriminant(1.0 - (niOverNt * niOverNt * (1.0 - (dt * dt))));

    if (discriminant > 0) {
        resultDestination = (niOverNt * (unitV - (dt * normal))) - (sqrt(discriminant) * normal);
        return true;
    }

    return false;
}
float schlick(float const cosine, float const refractionIndex) {
    float r0((1 - refractionIndex) / (1 + refractionIndex));
    r0 *= r0;

    return r0 + ((1.0 - r0) * pow((1.0 - cosine), 5));
}
