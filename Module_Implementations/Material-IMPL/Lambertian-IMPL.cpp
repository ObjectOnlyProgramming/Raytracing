module Lambertian;

import Randomizer;

import Ray;

import Color;

import HitRecord;




Lambertian::Lambertian(const Color& initial_albedo) :

Lambertian_albedo {initial_albedo}

{

} /* Lambertian Parameter Constructor */




bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered,
                         const Randomizer& randomizer) const
{
    auto scatter_direction {rec.GET_NORMAL() + randomizer.random_unit_Vector3D()};

    if (scatter_direction.near_zero())
    {
        scatter_direction = rec.GET_NORMAL();

    } /* Discard Vector3Ds that are too close to zero to avoid infinites and NaNs */

    scattered = Ray(rec.GET_P(), scatter_direction);

    attenuation = Lambertian_albedo;

    return true;

} /* How the reflectance should scatter when objects using this material are hit by the Camera's rays */