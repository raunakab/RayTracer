#include <sphere.h>

Sphere::Sphere(Vec3 const & center, float const radius) : Hittable(), center(center), radius(radius) {}
Sphere::~Sphere() {}

bool Sphere::hit(Ray const & r, float const t_min, float const t_max, HitRecord & hr) const {
    Vec3 const & ctr(this->center);
    float const & rad(this->radius);

    Vec3 const OtoC(r.origin() - ctr);
    Vec3 const & rDir(r.direction());

    float const a(dot(rDir, rDir));
    float const b(dot(rDir, OtoC));
    float const c(dot(OtoC, OtoC) - (rad*rad));
    float const discriminant((b*b) - (a*c));

    if (discriminant > 0) {
        float const firstTerm(-b / a);
        float const secondTerm(sqrt(discriminant) / a);

        float root(firstTerm - secondTerm);
        if (t_min < root && root < t_max) {
            hr.t = root;
            hr.p = r.pointAtParameter(root);
            hr.normal = (hr.p - ctr) / rad;

            return true;
        }

        root = firstTerm + secondTerm;
        if (t_min < root && root < t_max) {
            hr.t = root;
            hr.p = r.pointAtParameter(root);
            hr.normal = (hr.p - ctr) / rad;

            return true;
        }
    }

    return false;
}
