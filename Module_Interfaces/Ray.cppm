export module Ray;

import Vector3D;

import Color;


export class Ray
{
    public:

        Ray();

        Ray(const Vector3D& initial_origin,
            const Vector3D& initial_direction);


        const Vector3D& GET_RAY_ORIGIN() const;

        const Vector3D& GET_RAY_DIRECTION() const;


        double Ray_direction_dot_product_with(const Vector3D& another_vec3) const;

        double Ray_direction_length_squared() const;

        
        Vector3D Ray_direction_unit_vector() const;

        Vector3D Ray_direction_reflect_with(const Vector3D& normal) const;
        
        Vector3D ray(double t) const;

    private:

        Vector3D Ray_origin;

        Vector3D Ray_direction;

}; /* Ray - A vector that is used to calculate color values for objects in a scene */