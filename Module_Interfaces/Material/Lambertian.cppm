export module Lambertian;


import Randomizer;

import Ray;

import HitRecord;

import Color;

import Material;


export class Lambertian : public Material
{
    public:

        Lambertian(const Color& initial_albedo);


        bool scatter(const Ray& r_in, const HitRecord& rec,
                     Color& attenuation, Ray& scattered,
                     const Randomizer& randomizer) const override;

    private:

        Lambertian();

        
        Color Lambertian_albedo;

}; /* LambertianMaterial - A Material that uses Lambertian reflectance
      (uniform scattering) */