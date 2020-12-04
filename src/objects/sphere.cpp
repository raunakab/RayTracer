#include <sphere.h>

Sphere::Sphere(Vec3 const & centre, float const radius, Material const * const material) :
Hittable(),
centre(centre),
radius(radius),
material(material) {}
Sphere::~Sphere() {
    delete this->material;
}

bool Sphere::hit(Ray const & r, float const t_min, float const t_max, HitRecord & hr) const {
    Vec3 const & ctr(this->centre);
    float const & rad(this->radius);

    Vec3 const OtoC(r.origin() - ctr);
    Vec3 const & rDir(r.direction());

    float const a(dot(rDir, rDir));
    float const b(dot(rDir, OtoC));
    float const c(dot(OtoC, OtoC) - (rad*rad));
    float const discriminant((b*b) - (a*c));

    if (discriminant > 0) {
        hr.material = this->material; /* DON'T KNOW ABOUT THIS ONE JUST YET! */

        float const firstTerm(-b / a);
        float const secondTerm(sqrt(discriminant) / a);

        float root(firstTerm - secondTerm);
        if (t_min < root && root < t_max) {
            hr.t0 = root;
            hr.hitPoint = r.pointAtParameter(root);
            hr.normal = (hr.hitPoint - ctr) / rad;

            return true;
        }

        root = firstTerm + secondTerm;
        if (t_min < root && root < t_max) {
            hr.t0 = root;
            hr.hitPoint = r.pointAtParameter(root);
            hr.normal = (hr.hitPoint - ctr) / rad;

            return true;
        }
    }

    return false;
}
