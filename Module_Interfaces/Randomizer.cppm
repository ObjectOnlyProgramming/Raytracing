export module Randomizer;

import Vector3D;

export struct Randomizer
{
    double random_double() const;

    double random_double(double min, double max) const;
    

    Vector3D random_Vector3D() const;

    Vector3D random_Vector3D(double min, double max) const;

    Vector3D random_unit_Vector3D() const;

    Vector3D random_Vector3D_on_hemisphere(const Vector3D& HitRecord_normal)
                                           const;

    Vector3D random_in_unit_disk() const;

}; /* Randomizer - Functions to create random objects and values */