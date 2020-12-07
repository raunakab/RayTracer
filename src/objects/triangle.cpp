#include <triangle.h>

Triangle::Triangle(Vec3 const & a, Vec3 const & b, Vec3 const & c, Material const * const material) :
a(a),
b(b),
c(c),
nonUnitNormal(cross(this->b - this->a, this->c - this->a)),
material(material)
{}
Triangle::~Triangle() {}

bool Triangle::hit(Ray const & ray, float const tMin, float const tMax, HitRecord & record) const {
    Vec3 const & a(this->a);
    Vec3 const & b(this->b);
    Vec3 const & c(this->c);
    Vec3 const & nonUnitNormal(this->nonUnitNormal);

    Vec3 const w(a - ray.origin());
    Vec3 const n(unitVector(nonUnitNormal));
    Vec3 const B(ray.direction());

    float const numerator(dot(w, n));
    float const denominator(dot(B, n));

    if (denominator == 0) return false;

    float const t0(numerator / denominator);

    Vec3 I(ray.pointAtParameter(t0));
    Vec3 const alpha(I - a);
    Vec3 const beta(I - b);
    Vec3 const gamma(I - c);

    float const areaGamma(cross(alpha, beta).length());
    float const areaBeta(cross(alpha, gamma).length());
    float const areaAlpha(cross(beta, gamma).length());
    float const totalArea(nonUnitNormal.length());
    float const barycentricArea((areaAlpha + areaBeta + areaGamma) / totalArea);

    if (!withinRange(barycentricArea, 1.0, 0.0001)) return false;
    if (t0 < tMin || tMax < t0) return false;

    record.material = this->material;
    record.t0 = t0;
    record.hitPoint = I;
    record.normal = n;

    return true;
}
