module Sphere;

import std;

import Interval;

import Vector3D;

import HitRecord;

import Hittable;


Sphere::Sphere(const Vector3D& initial_center, double initial_radius,
               const std::shared_ptr<Material>& applied_material) :

Sphere_center {initial_center},

Sphere_radius {std::fmax(0, initial_radius)},

Sphere_material {applied_material}

{

} /* Sphere Parameter Constructor */




bool Sphere::hit(const Ray& r, Interval ray_t_values, HitRecord& rec,
                 std::shared_ptr<Material>& material) const
{
    Vector3D oc {Sphere_center - r.GET_RAY_ORIGIN()};

    auto a {r.Ray_direction_length_squared()};

    auto h {r.Ray_direction_dot_product_with(oc)};

    auto c {oc.length_squared() - Sphere_radius * Sphere_radius};

    auto discriminant {h * h - a * c};

    if (discriminant < 0)
    {
        return false;

    } /* If the discriminant is less than 0, the ray has not hit this
         Sphere */

    auto sqrtd {std::sqrt(discriminant)};

    // Find the nearest root that lies in the acceptable range

    auto root {(h - sqrtd) / a};

    if (!ray_t_values.surrounds(root))
    {
        root = (h + sqrtd) / a;

        if (!ray_t_values.surrounds(root))
        {
            return false;

        } /* If the root is still outside the acceptable range, the ray has
             not hit this Sphere */

    } /* If the root is outside the acceptable range, try inverting it and
         check again. */

    rec.set_t_value(root);

    rec.set_p(r.ray(rec.GET_T_VALUE()));

    Vector3D outward_normal {(rec.GET_P() - Sphere_center) / Sphere_radius};

    rec.set_face_normal(r, outward_normal);

    material = Sphere_material;

    return true;

} /* Determines if the Sphere has been hit by a ray that was casted by the
     Camera */