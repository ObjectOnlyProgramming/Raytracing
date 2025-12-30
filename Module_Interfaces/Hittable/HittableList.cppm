export module HittableList;


import std;

import Randomizer;

import Interval;

import Ray;

import HitRecord;

import Hittable;

import Material;

export class HittableList : public Hittable
{
    public:

        HittableList(const Randomizer& randomizer);

        HittableList(std::shared_ptr<Hittable> added_hittable_object);


        bool hit(const Ray& r, Interval ray_t_values, HitRecord& rec,
                 std::shared_ptr<Material>& material) const override;


        void clear();

        void add(std::shared_ptr<Hittable> new_hittable_object);

    private:

        std::vector<std::shared_ptr<Hittable>> HittableList_objects;

        
        void create_Spheres(const Randomizer& randomizer);


}; /* HittableList - A list of objects that are derived from the Hittable
      abstract class */