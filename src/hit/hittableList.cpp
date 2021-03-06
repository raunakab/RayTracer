#include <hittableList.h>
#include <Logger/logger.h>

HittableList::HittableList(Hittable ** const list, int const length) : list(list), length(length) {}
HittableList::~HittableList() {
    Hittable ** & list(this->list);
    int const & length(this->length);

    for (int i(0); i<length; ++i) delete list[i];
    delete this->list;
}

bool HittableList::hit(Ray const & r, float const t_min, float const t_max, HitRecord & hr) const {
    float const length(this->length);
    Hittable ** list(this->list);

    bool hitAnything(false);
    float closestSoFar(t_max);
    HitRecord aggregateHitRecord(0.0, Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0), nullptr);

    for (unsigned int i(0); i<length; ++i) if (list[i]->hit(r, t_min, closestSoFar, aggregateHitRecord)) {
        hr = aggregateHitRecord;
        closestSoFar = hr.t0;
        hitAnything = true;
    }
    return hitAnything;
}
