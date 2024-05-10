#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP

#include "hittable.hpp"
#include <memory>
#include <vector>

using hittable_p = std::shared_ptr<hittable>;

class hittable_list : public hittable {
public:
    std::vector<hittable_p> objects_;
    hittable_list() = default;
    hittable_list(hittable_p obj) {
        this->add(obj);
    }

    void add(hittable_p obj) {
        objects_.push_back(obj);
    }
    void clear() {
        objects_.clear();
    }

    bool hit(const ray& r, interval ray_t, hitted_surf& tangent_surf) const override {
        hitted_surf temp_surf;
        bool hit_any = false;
        auto closest_so_far = ray_t.max_;

        for (const auto& object : objects_) {
            if (object->hit(r, interval(ray_t.min_, closest_so_far), temp_surf)) {
                hit_any = true;
                closest_so_far = temp_surf.t_;
                tangent_surf = temp_surf;
            }
        }

        return hit_any;
    }

};

#endif