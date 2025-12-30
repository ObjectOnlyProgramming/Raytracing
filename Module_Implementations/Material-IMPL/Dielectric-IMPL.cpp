module Dielectric;

import std;

import Vector3D;

import Ray;

import HitRecord;

import Color;

import Randomizer;




Dielectric::Dielectric(double refraction_index) :

Dielectric_refraction_index {refraction_index}

{

} /* Dielectric Parameter Constructor */




bool Dielectric::scatter(const Ray& r_in, const HitRecord& rec, Color& attenuation, Ray& scattered,
                         const Randomizer& randomizer) const
{
    attenuation = Color(1.0, 1.0, 1.0);

    double ri {rec.GET_FRONT_FACE() ? (1.0 / Dielectric_refraction_index) : Dielectric_refraction_index};

    Vector3D unit_direction {r_in.Ray_direction_unit_vector()};


    double cos_theta {std::fmin(-unit_direction.dot(rec.GET_NORMAL()), 1.0)};

    double sin_theta {std::sqrt(1.0 - cos_theta * cos_theta)};


    bool cannot_refract {ri * sin_theta > 1.0};

    Vector3D direction;


    if (cannot_refract || reflectance(cos_theta, ri) > randomizer.random_double())
    {
        direction = unit_direction.reflect(rec.GET_NORMAL());

    } /* If the Camera's ray cannot be refracted, reflect it instead */

    else
    {
        direction = unit_direction.refract(rec.GET_NORMAL(), ri);

    } /* Always refract when possible */


    scattered = Ray(rec.GET_P(), direction);

    return true;

} /* Scatters the Camera's rays with refraction included */




double Dielectric::reflectance(double cosine, double refraction_index) const
{
    auto r0 {(1 - refraction_index) / (1 + refraction_index)};

    r0 = r0 * r0;

    return r0 + (1 - r0) * std::pow((1 - cosine), 5);

} /* Calculates reflectivity that varies depending on the angle by using the Schlick Approximation */