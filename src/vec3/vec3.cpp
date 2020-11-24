#include "vec3.h"

vec3::vec3(float const e0, float const e1, float const e2) {
    // initializer list does not work for clang++
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;

    return;
}
vec3::~vec3() {}
