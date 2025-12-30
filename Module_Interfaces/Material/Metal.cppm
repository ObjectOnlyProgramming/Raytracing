export module Metal;


import Material;

import Randomizer;

import Ray;

import Color;

import HitRecord;


export class Metal : public Material
{
    public:

        Metal(const Color& initial_albedo, double initial_fuzz);


        bool scatter(const Ray& r_in, const HitRecord& rec,
                     Color& attenuation, Ray& scattered,
                     const Randomizer& randomizer) const override;
                     
    private:

        Metal();


        Color Metal_albedo;

        
        double Metal_fuzz;

}; /* MetalMaterial - A metal material */