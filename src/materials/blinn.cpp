#include <blinn.h>

Blinn::Blinn(Vec3 const & albedo, float const shininess, float const kAmbient, float const kDiffuse, float const kSpecular) :
BlackBody(albedo),
shininess(shininess),
kAmbient(kAmbient),
kDiffuse(kDiffuse),
kSpecular(kSpecular)
{}
Blinn::~Blinn() {}

bool Blinn::scatter(Ray const & rayIn, HitRecord const & record, Vec3 & attenuation, Ray & scattered, Light const * const light) const {
    Vec3 const & ambientColour(this->albedo);
    Vec3 const & materialColour(this->albedo);
    Vec3 const & lightColour(light->lightColour);

    Vec3 const & hitPoint(record.hitPoint);
    Vec3 const & N(record.normal);
    Vec3 const L((light->lightPosition - hitPoint));
    Vec3 const V((rayIn.direction()));
    Vec3 const H((L + V) / 2.0);

    // Ambient
    Vec3 const & ambient(ambientColour);

    // Diffuse
    float nlAngle(dot(N, L));
    if (nlAngle < 0.0) nlAngle = 0.0;
    Vec3 const diffuse(nlAngle * (materialColour * lightColour));

    // Specular
    float hvAngle(dot(H, N));
    if (hvAngle < 0.0) hvAngle = 0.0;
    else pow(hvAngle, this->shininess);
    Vec3 const specular(hvAngle * lightColour);

    // Vec3 reflectedPoint(0.0, 0.0, 0.0);
    // reflect(V, N, reflectedPoint);
    scattered = Ray(hitPoint, N + randomUnitVector());

    // if (dot(L, N) > 0.0) attenuation = unitVector((this->kAmbient * ambient) + (this->kDiffuse * diffuse) + (this->kSpecular * specular));
    // else attenuation = unitVector((this->kAmbient * ambient) + (this->kDiffuse * diffuse));
    attenuation = unitVector((this->kAmbient * ambient) + (this->kDiffuse * diffuse) + (this->kSpecular * specular));

    // return dot(L, N) > 0.0;
    return true;
}
