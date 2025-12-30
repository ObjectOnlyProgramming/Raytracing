export module Camera;


import std;

import Vector3D;

import Color;

import Ray;

import Hittable;

import HittableList;

import Randomizer;

import Material;




export class Camera
{
    public:

        Camera(int Raytracer_image_width, double Raytracer_aspect_ratio,
               int Raytracer_samples_per_pixel,
               double Raytracer_vertical_field_of_view,
               double Raytracer_focus_distance,
               Vector3D Raytracer_look_from, Vector3D Raytracer_look_at,
               Vector3D Raytracer_up_vector, double Raytracer_defocus_angle,
               int Raytracer_max_raybounce_depth,
               const HittableList& Raytracer_world);


        const Vector3D& GET_CAMERA_CENTER() const;

        const Vector3D& GET_PIXEL_DELTA_U() const;

        const Vector3D& GET_PIXEL_DELTA_V() const;

        const Vector3D& GET_PIXEL_0_0_LOCATION() const;

        const Vector3D& GET_VIEWPORT_UPPER_LEFT() const;


        const double& GET_PIXEL_SAMPLE_SCALE() const;


        const int& GET_IMAGE_WIDTH() const;

        const int& GET_IMAGE_HEIGHT() const;

        const int& GET_MAX_COLOR_AMOUNT() const;

        const int& GET_SAMPLES_PER_PIXEL() const;

        const int& GET_MAX_RAY_BOUNCE_DEPTH() const;


        Vector3D sample_square(const Randomizer& randomizer) const;


        Ray cast_ray(int column, int row, const Randomizer& randomizer)
                     const;


        Color ray_color(const Ray& r,
                        const int& Camera_max_ray_bounce_depth,
                        const Hittable& Raytracer_world,
                        const Randomizer& randomizer,
                        std::shared_ptr<Material>& material);

    private:

        Camera();


        int Camera_image_width {};


        double Camera_aspect_ratio {16.0 / 9.0};


        int Camera_image_height {};

        int Camera_samples_per_pixel {};
        

        double Camera_pixel_sample_scale {};


        double Camera_vertical_field_of_view {};

        double degrees_to_radians(double degrees);

        double Camera_focus_distance {};

        double Camera_theta {};
        
        double Camera_h {};

        double Camera_viewport_height {2.0};

        double Camera_viewport_width {};


        Vector3D Camera_look_from {};

        Vector3D Camera_look_at {};

        Vector3D Camera_w;

        Vector3D Camera_up_vector {};

        Vector3D Camera_u;

        Vector3D Camera_v;

        Vector3D Camera_viewport_u {};

        Vector3D Camera_viewport_v {};

        Vector3D Camera_center {};

        Vector3D Camera_viewport_upper_left {};

        Vector3D Camera_pixel_delta_u {};

        Vector3D Camera_pixel_delta_v {};

        Vector3D Camera_pixel_0_0_location {};


        double Camera_defocus_angle {};

        double Camera_defocus_radius {};


        Vector3D Camera_defocus_disk_u;

        Vector3D Camera_defocus_disk_v;


        int Camera_MAX_COLOR_AMOUNT {255};

        int Camera_max_ray_bounce_depth {};


        Vector3D defocus_disk_sample(const Randomizer& randomizer) const;


        Color Camera_color {};

}; /* Camera - "Looks" at the objects in the scene and casts rays to
      determine their color values */