#include <parallelepiped.h>
#include <lambertian.h>

Parallelepiped::Parallelepiped(Vec3 const & origin, Vec3 const & basis0, Vec3 const & basis1, Vec3 const & basis2, Material const * const material) :
meshCount(12),
origin(origin),
basis0(basis0),
basis1(basis1),
basis2(basis2),
material(material),
hittableList(this->determineHittableList(), 12)
{}
Parallelepiped::~Parallelepiped() { delete this->material; }

Hittable ** Parallelepiped::determineHittableList() const {
    Vec3 const & b0(this->basis0);
    Vec3 const & b1(this->basis1);
    Vec3 const & b2(this->basis2);

    Vec3 const & p0(this->origin);
    Vec3 const p1(p0 + b2);
    Vec3 const p2(p0 + b1);
    Vec3 const p3(p2 + b2);

    Vec3 const p4(p0 + b0);
    Vec3 const p5(p4 + b2);
    Vec3 const p6(p4 + b1);
    Vec3 const p7(p6 + b2);

    Hittable ** list = new Hittable*[this->meshCount];

    /** for debugging purposes ONLY!!! colours the individual triangle meshes to bright, unique colours! */
    // list[0] = new Triangle(p0, p2, p1, new Lambertian(Vec3(0.0, 1.0, 0.4)));
    // list[1] = new Triangle(p3, p1, p2, new Lambertian(Vec3(0.1, 0.9, 0.3)));
    // list[2] = new Triangle(p5, p7, p4, new Lambertian(Vec3(0.2, 0.8, 0.2)));
    // list[3] = new Triangle(p6, p4, p7, new Lambertian(Vec3(0.3, 0.7, 0.1)));
    // list[4] = new Triangle(p0, p1, p4, new Lambertian(Vec3(0.4, 0.6, 0.0)));
    // list[5] = new Triangle(p5, p4, p1, new Lambertian(Vec3(0.5, 0.5, 1.0)));
    // list[6] = new Triangle(p6, p7, p2, new Lambertian(Vec3(0.6, 0.4, 0.9)));
    // list[7] = new Triangle(p3, p2, p7, new Lambertian(Vec3(0.7, 0.3, 0.8)));
    // list[8] = new Triangle(p0, p4, p2, new Lambertian(Vec3(0.8, 0.2, 0.7)));
    // list[9] = new Triangle(p6, p2, p4, new Lambertian(Vec3(0.9, 0.1, 0.6)));
    // list[10] = new Triangle(p3, p7, p1, new Lambertian(Vec3(1.0, 0.0, 0.0)));
    // list[11] = new Triangle(p5, p1, p7, new Lambertian(Vec3(0.0, 1.0, 0.5)));

    // xL
    list[0] = new Triangle(p0, p2, p1, this->material);
    list[1] = new Triangle(p3, p1, p2, this->material);

    // // xR
    list[2] = new Triangle(p5, p7, p4, this->material);
    list[3] = new Triangle(p6, p4, p7, this->material);

    // // yB
    list[4] = new Triangle(p0, p1, p4, this->material);
    list[5] = new Triangle(p5, p4, p1, this->material);

    // // yT
    list[6] = new Triangle(p6, p7, p2, this->material);
    list[7] = new Triangle(p3, p2, p7, this->material);

    // // zN
    list[8] = new Triangle(p0, p4, p2, this->material);
    list[9] = new Triangle(p6, p2, p4, this->material);

    // // zF
    list[10] = new Triangle(p3, p7, p1, this->material);
    list[11] = new Triangle(p5, p1, p7, this->material);
    
    return list;
}

bool Parallelepiped::hit(Ray const & ray, float const tMin, float const tMax, HitRecord & record) const {
    if (this->hittableList.hit(ray, tMin, tMax, record)) return true;
    else return false;
}
