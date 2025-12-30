export module Dielectric;


import Ray;

import HitRecord;

import Color;

import Randomizer;

import Material;


export class Dielectric : public Material
{
    public:

        Dielectric(double refraction_index);

        
        bool scatter(const Ray& r_in, const HitRecord& rec,
                     Color& attenuation, Ray& scattered,
                     const Randomizer& randomizer) const override;
    private:

        double Dielectric_refraction_index {};

        double reflectance(double cosine, double refraction_index) const;

}; /* Dielectric - A Material that always refracts whenever possible and
                   reflects if it can't */