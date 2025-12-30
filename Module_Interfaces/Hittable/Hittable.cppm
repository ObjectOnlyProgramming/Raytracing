export module Hittable;

import std;

import Interval;

import Vector3D;

import Ray;

import HitRecord;

import Material;


export class Hittable
{
    public:

        virtual ~Hittable() = default;

        
        virtual bool hit(const Ray& r, Interval ray_t_values,
                         HitRecord& rec,
                         std::shared_ptr<Material>& material) const = 0;

}; /* Hittable - Objects derived from this abstract class can be hit by the
      Camera's rays. */