export module Sphere;


import std;

import Interval;

import Vector3D;

import Ray;

import Hittable;

import HitRecord;

import Material;


export class Sphere : public Hittable
{
    public:

        Sphere(const Vector3D& initial_center, double initial_radius,
               const std::shared_ptr<Material>& applied_material);

        bool hit(const Ray& r, Interval ray_t_values, HitRecord& rec,
                 std::shared_ptr<Material>& material) const override;

    private:

        Vector3D Sphere_center;


        double Sphere_radius {};

        
        std::shared_ptr<Material> Sphere_material;

}; /* Sphere - An object that can be hit by the Camera's rays */