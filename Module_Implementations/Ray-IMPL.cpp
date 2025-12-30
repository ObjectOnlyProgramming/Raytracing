module Ray;

import Vector3D;

import Color;




Ray::Ray()
{

} /* Ray Default Constructor */


Ray::Ray(const Vector3D& initial_origin, const Vector3D& initial_direction) :

Ray_origin {initial_origin},

Ray_direction {initial_direction}

{

} /* Ray Parameter Constructor */




const Vector3D& Ray::GET_RAY_ORIGIN() const
{
    return Ray_origin;

} /* Ray_origin GETTER */

const Vector3D& Ray::GET_RAY_DIRECTION() const
{
    return Ray_direction;

} /* Ray_direction GETTER */




double Ray::Ray_direction_dot_product_with(const Vector3D& another_Vector3D) const
{
    return Ray_direction.dot(another_Vector3D);

} /* Use Ray_direction to call the Vector3D dot function with
     another_Vector3D */

double Ray::Ray_direction_length_squared() const
{
    return Ray_direction.length_squared();

} /* Use Ray_direction to call the Vector3D length_squared function */


Vector3D Ray::Ray_direction_unit_vector() const
{
    return Ray_direction.unit_vector();

} /* Use Ray_direction to call the Vector3D unit_vector function */

Vector3D Ray::Ray_direction_reflect_with(const Vector3D& normal) const
{
    return Ray_direction.reflect(normal);

} /* Use Ray_direction to call the Vector3D reflect function with a normal */


Vector3D Ray::ray(double real_number) const
{
    return Ray_origin + (real_number * Ray_direction);

} /* Moves to a certain position along the ray. (P(t) = A + t * b) */