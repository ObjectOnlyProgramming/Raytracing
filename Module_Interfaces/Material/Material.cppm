export module Material;


import Randomizer;

import Color;

import Ray;

import HitRecord;


export class Material
{
    public:

        virtual ~Material() = default;

        
        virtual bool scatter(const Ray& r_in, const HitRecord& rec,
                             Color& attenuation, Ray& scattered,
                             const Randomizer& randomizer) const
        {
            return false;
        }

}; /* Material - Contains Colors, Ambient Occlusion, Normal Maps, etc. to
      render an object */