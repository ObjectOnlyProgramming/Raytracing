module Metal;


import Ray;

import HitRecord;

import Color;

import Randomizer;

import Vector3D;




Metal::Metal(const Color& initial_albedo, double initial_fuzz) :

Metal_albedo {initial_albedo},

Metal_fuzz {(initial_fuzz < 1) ? initial_fuzz : 1}

{

} /* Metal Parameter Constructor */




bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered,
                     const Randomizer& randomizer) const
{
    Vector3D reflected {r_in.Ray_direction_reflect_with(rec.GET_NORMAL())};

    reflected = reflected.unit_vector() + Metal_fuzz * randomizer.random_unit_Vector3D();

    scattered = Ray(rec.GET_P(), reflected);

    attenuation = Metal_albedo;

    return (scattered.Ray_direction_dot_product_with(rec.GET_NORMAL()) > 0.0);

} /* Scatters the Camera's rays with a reflectance function for the Metal Material */