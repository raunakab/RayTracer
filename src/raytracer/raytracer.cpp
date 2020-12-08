#include <raytracer.h>
#include <pointLight.h>

RayTracer::RayTracer(
    std::string const && filePath,
    Light const * const && light,
    Camera const && camera,
    Hittable const * const && hittable,
    int const maxBounce
) :
filePath(filePath),
light(light),
camera(std::move(camera)),
hittable(hittable),
maxBounce(maxBounce) {}
RayTracer::~RayTracer() {
    delete this->light;
    delete this->hittable;
}

Vec3 RayTracer::colour(Ray const & ray, int const currentBounce) const {
    HitRecord record;
    Hittable const * const & hittable(this->hittable);

    if (hittable->hit(ray, 0.001, MAXFLOAT, record)) {
        Ray scattered(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0));
        Vec3 attenuation(0.0, 0.0, 0.0);
        Vec3 const & hitPoint(record.hitPoint);

        if (currentBounce < maxBounce && record.material && record.material->scatter(ray, record, attenuation, scattered, this->light)) {
            float const contribution(this->light->contribution(hittable, hitPoint));
            return contribution * (attenuation * this->colour(scattered, currentBounce + 1));
        }
        else return Vec3(0.0, 0.0, 0.0);
    } else {
        Vec3 dir(ray.direction());
        dir.makeUnitVector();

        float const t(0.5 * (dir.y() + 1.0));

        return ((1.0 - t) * Vec3(1.0, 1.0, 1.0)) + (t * Vec3(0.5, 0.7, 1.0));
    }
}

void RayTracer::start(int const nx, int const ny, int const ns) const {
    std::ofstream fs;
    fs.open(this->filePath + ".ppm");
    fs << "P3\n" << nx << " " << ny << "\n255\n";

    for (int j(ny - 1); j>=0; --j) for (int i(0); i<nx; ++i) {
        Vec3 col(0.0, 0.0, 0.0);

        for (int s(0); s<ns; ++s) {
            float u((float(i) + drand48()) / float(nx));
            float v((float(j) + drand48()) / float(ny));

            col += this->colour(this->camera.getRay(u,v), 0);
        }
        col /= float(ns);

        col.e[0] = sqrt(col.e[0]);
        col.e[1] = sqrt(col.e[1]);
        col.e[2] = sqrt(col.e[2]);

        col *= 255.99;
        fs << col;
    }

    fs.close();
}
