#include <light.h>

Light::Light(Vec3 const & lightPosition, float const lightContribution, float const shadowContribution, float const lightFuzz) :
lightPosition(lightPosition),
lightContribution(lightContribution),
shadowContribution(shadowContribution),
lightFuzz(lightFuzz)
{}
Light::~Light() {}
