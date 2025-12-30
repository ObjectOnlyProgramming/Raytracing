module Randomizer;

import std;

import Vector3D;




double Randomizer::random_double() const
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    return distribution(gen);

} /* Creates a random double using the mt19937 generator */


double Randomizer::random_double(double min, double max) const
{
    return min + (max - min) * random_double();

} /* Creates a random double between the min and max values */




Vector3D Randomizer::random_Vector3D() const
{
    return Vector3D(random_double(), random_double(), random_double());

} /* Creates a Vector3D with random values between 0.0 and 1.0 */


Vector3D Randomizer::random_Vector3D(double min, double max) const
{
    return Vector3D(random_double(min, max), random_double(min, max),
                    random_double(min, max));

} /* Creates an unnormalized Vector3D with random values between the min
     and max values */


Vector3D Randomizer::random_unit_Vector3D() const
{
    while (true)
    {
        auto p {random_Vector3D(-1.0, 1.0)};

        auto lensq {p.length_squared()};

        /* Vector3Ds with values below 10 to power -160 (1e-160) are
           rejected */
        if (1e-160 < lensq && lensq <= 1)
        {

            return p / std::sqrt(lensq);

        } /* If a valid Vector3D is found, normalize it. */

    } /* Keeps generating random Vector3Ds until one is on or inside the
         Hittable object. */

} /* Creates a random normalized Vector3D */


Vector3D Randomizer::random_Vector3D_on_hemisphere(
        const Vector3D& HitRecord_normal) const
{
    Vector3D on_unit_sphere {random_unit_Vector3D()};

    if (on_unit_sphere.dot(HitRecord_normal) > 0.0)
    {
        return on_unit_sphere;

    } /* If the dot product is positive, the Vector3D is in the same
         hemisphere as the normal */

    else
    {
        return -on_unit_sphere;

    } /* If the dot product is negative, invert it so it can be in the same
         hemisphere as the normal */
    
} /* If the dot product of a random Vector3D and normal is positive, return
     it. Otherwise, return it inverted */


Vector3D Randomizer::random_in_unit_disk() const
{
    while (true)
    {
        auto p {Vector3D(random_double(-1.0, 1.0), random_double(-1.0, 1.0), 0.0)};

        if (p.length_squared() < 1)
        {
            return p;

        } /* If the random Vector3D's length squared is less than 1, it's
             inside the unit disk so return it */
        
    } /* Keep generating random Vector3Ds until one of them is inside the
         unit disk */

} /* Generate random points inside the Camera's unit disk to calculate
     defocus blur */