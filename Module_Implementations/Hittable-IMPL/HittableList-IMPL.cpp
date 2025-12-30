module HittableList;


import std;

import Randomizer;

import Interval;

import Vector3D;

import Ray;

import Color;

import HitRecord;

import Hittable;

import Sphere;

import Material;

import Lambertian;

import Metal;

import Dielectric;




HittableList::HittableList(const Randomizer& randomizer)
{
    create_Spheres(randomizer);
    
} /* HittableList Parameter Constructor */




bool HittableList::hit(const Ray& r, Interval ray_t_values, HitRecord& rec,
                       std::shared_ptr<Material>& material) const
{
    HitRecord temp_rec;

    bool hit_anything {};

    auto closest_so_far {ray_t_values.GET_INTERVAL_MAX()};

    for (const auto& hittable_object : HittableList_objects)
    {
        if (hittable_object->hit(r, Interval(
            ray_t_values.GET_INTERVAL_MIN(), closest_so_far),
            temp_rec, material))
        {
            hit_anything = true;

            closest_so_far = temp_rec.GET_T_VALUE();

            rec = temp_rec;

        } /* If the condition is met, a Hittable object in this list has
             been hit by a ray from the Camera. */

    } /* For every Hittable object in this list of Hittable objects, check
         if a ray has hit it. */

    return hit_anything;
    
} /* Checks if any of the Hittable objects in this list have been hit by
     the Camera's rays */




void HittableList::clear()
{
    HittableList_objects.clear();

} /* Remove all objects from this list */


void HittableList::add(std::shared_ptr<Hittable> new_hittable_object)
{
    HittableList_objects.emplace_back(new_hittable_object);

} /* Adds a Hittable object to this list */


void HittableList::create_Spheres(const Randomizer& randomizer)
{
    auto ground_material {std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5))};

    HittableList_objects.emplace_back(std::make_shared<Sphere>(
                         Vector3D(0.0, -1000, 0.0), 1000, ground_material));

    for (int a {-11}; a < 11; a++)
    {
        for (int b {-11}; b < 11; b++)
        {
            auto choose_mat {randomizer.random_double()};

            Vector3D center {a + 0.9 * randomizer.random_double(),
                             0.2, b + 0.9 * randomizer.random_double()};

            if ((center - Vector3D(4, 0.2, 0.0)).length() > 0.9)
            {
                std::shared_ptr<Material> sphere_material;

                if (choose_mat < 0.8)
                {
                    auto albedo {Color(randomizer.random_Vector3D()) *
                                 Color(randomizer.random_Vector3D())};

                    sphere_material = std::make_shared<Lambertian>(albedo);

                    HittableList_objects.emplace_back(
                                    std::make_shared<Sphere>(
                                    center, 0.2, sphere_material));

                } /* Add a Sphere with a Lamertian Material if the random
                     choose_mat value is less than 0.8 */

                else if (choose_mat < 0.95)
                {
                    auto albedo {Color(randomizer.random_Vector3D(0.5, 1.0))};

                    auto fuzz {randomizer.random_double(0.0, 0.5)};

                    sphere_material = std::make_shared<Metal>(albedo, fuzz);

                    HittableList_objects.emplace_back(
                                            std::make_shared<Sphere>(
                                            center, 0.2, sphere_material));

                } /* Add a Sphere with a Metal Material if the random
                     choose_mat value is 0.8 - 0.94 */

                else
                {
                    sphere_material = std::make_shared<Dielectric>(1.5);

                    HittableList_objects.emplace_back(
                        std::make_shared<Sphere>(
                        center, 0.2, sphere_material));

                } /* Add a Sphere with a Dielectric(Glass) Material if the
                     random choose_mat value is 0.95 or greater */

            } /* Positioning the Spheres with random X values */

        } /* Creates 22 Materials for the Spheres */

    } /* Creates 22 Spheres */

    // Large Sphere with a glass Material

    auto material1 {std::make_shared<Dielectric>(1.5)};

    HittableList_objects.emplace_back(
        std::make_shared<Sphere>(Vector3D(0.0, 1.0, 0.0), 1.0, material1));


    // Large Sphere with a Lambertian(Diffuse) Material

    auto material2 {std::make_shared<Lambertian>(Color(0.4, 0.2, 0.1))};

    HittableList_objects.emplace_back(
        std::make_shared<Sphere>(Vector3D(-4.0, 1.0, 0.0), 1.0, material2));


    // Large Sphere with a Metal Material

    auto material3 {std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0)};

    HittableList_objects.emplace_back(
        std::make_shared<Sphere>(Vector3D(4.0, 1.0, 0.0), 1.0, material3));

} /* Creates Spheres to be rendered by the Raytracer */