#include <hittable_list.h>

HittableList::HittableList(Hittable ** const list, int const length) : list(list), length(length) {}
HittableList::~HittableList() {
    Hittable ** & list(this->list);
    int const & length(this->length);

    for (int i(0); i<length; ++i) delete list[i];
}

bool HittableList::hit(Ray const & r, float const t_min, float const t_max, HitRecord & hr) const {
    bool hitAnything(false);
    float closestSoFar(t_max);
    HitRecord aggregateHitRecord(0.0, Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0));

    for (unsigned int i(0); i<this->length; ++i) {
        // std::cout << "a\n";

        // if ((*(this->list) + i)->hit(r, t_min, closestSoFar, aggregateHitRecord)) {
        //     hr = aggregateHitRecord;
        //     closestSoFar = hr.t;
        //     hitAnything = true;
        // }

        if (((this->list)[i])->hit(r, t_min, closestSoFar, aggregateHitRecord)) {
            hr = aggregateHitRecord;
            closestSoFar = hr.t;
            hitAnything = true;
        }

        // std::cout << "b\n";
    }

    return hitAnything;
}
