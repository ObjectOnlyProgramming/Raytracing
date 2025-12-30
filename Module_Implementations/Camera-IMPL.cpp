module Camera;


import std;

import Interval;

import Vector3D;

import Color;

import Ray;

import HitRecord;

import Hittable;

import Material;

import HittableList;

import Randomizer;




Camera::Camera(int Raytracer_image_width, double Raytracer_aspect_ratio,
               int Raytracer_samples_per_pixel,
               double Raytracer_vertical_field_of_view,
               double Raytracer_focus_distance,
               Vector3D Raytracer_look_from, Vector3D Raytracer_look_at,
               Vector3D Raytracer_up_vector, double Raytracer_defocus_angle,
               int Raytracer_max_raybounce_depth,
               const HittableList& Raytracer_world) :

Camera_image_width {Raytracer_image_width},

Camera_aspect_ratio {Raytracer_aspect_ratio},

Camera_image_height {static_cast<int>(Camera_image_width /
                                      Camera_aspect_ratio)},

Camera_samples_per_pixel {Raytracer_samples_per_pixel},

Camera_pixel_sample_scale {1.0 / Camera_samples_per_pixel},

Camera_vertical_field_of_view {Raytracer_vertical_field_of_view},

Camera_theta {degrees_to_radians(Camera_vertical_field_of_view)},

Camera_h {std::tan(Camera_theta / 2.0)},

Camera_focus_distance {Raytracer_focus_distance},

Camera_viewport_height {2 * Camera_h * Camera_focus_distance},

Camera_viewport_width {Camera_viewport_height *
        (static_cast<double>(Camera_image_width) / Camera_image_height)},

Camera_look_from {Raytracer_look_from},

Camera_look_at {Raytracer_look_at},

Camera_w {(Camera_look_from - Camera_look_at).unit_vector()},

Camera_up_vector {Raytracer_up_vector},

Camera_u {(Camera_up_vector.cross(Camera_w)).unit_vector()},

Camera_v {Camera_w.cross(Camera_u)},

Camera_viewport_u {Camera_viewport_width * Camera_u},

Camera_viewport_v {Camera_viewport_height * -Camera_v},

Camera_center {Camera_look_from},

Camera_viewport_upper_left {Camera_center -
                           (Camera_focus_distance * Camera_w) -
                            Camera_viewport_u / 2 -
                            Camera_viewport_v / 2},

Camera_pixel_delta_u {Camera_viewport_u / Camera_image_width},

Camera_pixel_delta_v {Camera_viewport_v / Camera_image_height},

Camera_pixel_0_0_location {Camera_viewport_upper_left + 0.5 *
                          (Camera_pixel_delta_u + Camera_pixel_delta_v)},

Camera_defocus_angle {Raytracer_defocus_angle},

Camera_defocus_radius {Camera_focus_distance *
                    std::tan(degrees_to_radians(Camera_defocus_angle / 2))},

Camera_defocus_disk_u {Camera_u * Camera_defocus_radius},

Camera_defocus_disk_v {Camera_v * Camera_defocus_radius},

Camera_max_ray_bounce_depth {Raytracer_max_raybounce_depth}

{
    Camera_image_height = (Camera_image_height < 1) ?
                           1 : Camera_image_height;

} /* Camera Parameter Constructor */




const Vector3D& Camera::GET_CAMERA_CENTER() const
{
    return Camera_center;

} /* Camera_center GETTER */


const Vector3D& Camera::GET_PIXEL_DELTA_U() const
{
    return Camera_pixel_delta_u;

} /* Camera_pixel_delta_u GETTER */


const Vector3D& Camera::GET_PIXEL_DELTA_V() const
{
    return Camera_pixel_delta_v;

} /* Camera_pixel_delta_v GETTER */


const Vector3D& Camera::GET_PIXEL_0_0_LOCATION() const
{
    return Camera_pixel_0_0_location;

} /* Camera_pixel_0_0_location GETTER */


const Vector3D& Camera::GET_VIEWPORT_UPPER_LEFT() const
{
    return Camera_viewport_upper_left;

} /* Camera_viewport_upper_left GETTER */




const double& Camera::GET_PIXEL_SAMPLE_SCALE() const
{
    return Camera_pixel_sample_scale;

} /* Camera_pixel_sample_scale GETTER */


const int& Camera::GET_IMAGE_WIDTH() const
{
    return Camera_image_width;

} /* Camera_image_width GETTER */


const int& Camera::GET_IMAGE_HEIGHT() const
{
    return Camera_image_height;

} /* Camera_image_height GETTER */


const int& Camera::GET_MAX_COLOR_AMOUNT() const
{
    return Camera_MAX_COLOR_AMOUNT;

} /* Camera_MAX_COLOR_AMOUNT GETTER */


const int& Camera::GET_SAMPLES_PER_PIXEL() const
{
    return Camera_samples_per_pixel;

} /* Camera_samples_per_pixel GETTER */


const int& Camera::GET_MAX_RAY_BOUNCE_DEPTH() const
{
    return Camera_max_ray_bounce_depth;

} /* Camera_max_ray_bounce_depth GETTER */




Vector3D Camera::sample_square(const Randomizer& randomizer) const
{
    return Vector3D(randomizer.random_double() - 0.5,
                    randomizer.random_double() - 0.5, 0.0);

} /* Generates random samples in the square that is centered at the origin */




Ray Camera::cast_ray(int column, int row, const Randomizer& randomizer)
                     const
{
    auto offset {sample_square(randomizer)};

    auto pixel_sample {this->Camera_pixel_0_0_location +
                      ((column + offset.GET_X_VALUE()) *
                      this->Camera_pixel_delta_u) +
                      ((row + offset.GET_Y_VALUE()) *
                      this->Camera_pixel_delta_v)};

    auto ray_origin {(Camera_defocus_angle <= 0) ?
                      Camera_center : defocus_disk_sample(randomizer)};

    auto ray_direction = pixel_sample - ray_origin;

    return Ray(ray_origin, ray_direction);

} /* Casts rays from this Camera to determine whether a Hittable object is
     hit */




Color Camera::ray_color(const Ray& r,
                        const int& Camera_max_ray_bounce_depth,
                        const Hittable& Raytracer_world,
                        const Randomizer& randomizer,
                        std::shared_ptr<Material>& material)
{
    if (Camera_max_ray_bounce_depth <= 0)
    {
        return Color(0.0, 0.0, 0.0);

    } /* If the Camera_max_ray_bounce_depth is exceeded,
         stop gathering light */


    HitRecord rec;


    if (Raytracer_world.hit(r, Interval(0.001,
        std::numeric_limits<double>::infinity()), rec, material))
    {
        Ray scattered;

        Color attenuation;

        if (material->scatter(r, rec, attenuation, scattered, randomizer))
        {
            return attenuation * ray_color(scattered,
                                           Camera_max_ray_bounce_depth - 1,
                                           Raytracer_world, randomizer,
                                           material);

        } /* Calculates the color based on the material that is applied to
             the object */

        return Color(0.0, 0.0, 0.0);
        
    } /* If a Hittable object is hit by a Ray, calculate the color */


    Vector3D unit_direction = r.Ray_direction_unit_vector();

    auto a = 0.5 * (unit_direction.GET_Y_VALUE() + 1.0);

    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);

} /* Calculate the Color of the Hittable object when it is hit by this
     Camera's ray */




double Camera::degrees_to_radians(double degrees)
{
    return degrees * std::numbers::pi / 180.0;

} /* Degrees to radians */




Vector3D Camera::defocus_disk_sample(const Randomizer& randomizer) const
{
    auto p {randomizer.random_in_unit_disk()};

    return Camera_center + (p.GET_X_VALUE() * Camera_defocus_disk_u) +
                           (p.GET_Y_VALUE() * Camera_defocus_disk_v);

} /* Returns a random point in the Camera's defocus disk */