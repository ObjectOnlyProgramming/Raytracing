module Raytracer;

import std;

import Vector3D;

import Ray;

import Color;




Raytracer::Raytracer(int initial_image_width, double initial_aspect_ratio,
                     int initial_samples_per_pixel,
                     double initial_vertical_field_of_view,
                     double initial_focus_distance,
                     Vector3D intial_look_from, Vector3D initial_look_at,
                     Vector3D initial_up_vector,
                     double initial_defocus_angle,
                     int initial_max_raybounce_depth) :

Raytracer_image_width {initial_image_width},

Raytracer_aspect_ratio {initial_aspect_ratio},

Raytracer_samples_per_pixel {initial_samples_per_pixel},

Raytracer_vertical_field_of_view {initial_vertical_field_of_view},

Raytracer_focus_distance {initial_focus_distance},

Raytracer_look_from {intial_look_from},

Raytracer_look_at {initial_look_at},

Raytracer_up_vector {initial_up_vector},

Raytracer_defocus_angle {initial_defocus_angle},

Raytracer_max_raybounce_depth {initial_max_raybounce_depth}

{
    render();

} /* Raytracer Parameter Constructor */




double Raytracer::linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
    {
        return std::sqrt(linear_component);

    } /* Changes the linear_component to a gamma 2.2 value */

    return 0;

} /* Converts from linear space to gamma space */




void Raytracer::write_color(std::ostream& output, const Color& pixel_color)
{
    auto r {pixel_color.GET_RED_VALUE()};

    auto g {pixel_color.GET_GREEN_VALUE()};

    auto b {pixel_color.GET_BLUE_VALUE()};


    r = linear_to_gamma(r);

    g = linear_to_gamma(g);

    b = linear_to_gamma(b);


    // Translate the [0, 1] component values to the byte range [0, 255]

    double intensity_min {0.000};

    double intensity_max {0.999};

    int rbyte {static_cast<int>(256 * std::clamp(r, intensity_min,
                                                 intensity_max))};

    int gbyte {static_cast<int>(256 * std::clamp(g, intensity_min,
                                                 intensity_max))};

    int bbyte {static_cast<int>(256 * std::clamp(b, intensity_min,
                                                 intensity_max))};

    // Write out the pixel color components

    output << rbyte << " " << gbyte << " " << bbyte << "\n";

} /* Writes the colors in a format compatible with a .ppm file */




void Raytracer::render()
{
    std::println("P3");

    std::println("{} {}", Raytracer_camera.GET_IMAGE_WIDTH(),
                 Raytracer_camera.GET_IMAGE_HEIGHT());

    std::println("{}", Raytracer_camera.GET_MAX_COLOR_AMOUNT());

    for (int row {}; row < Raytracer_camera.GET_IMAGE_HEIGHT(); row++)
    {
        std::clog << "\r Scanlines Remaining: "
                  <<Raytracer_camera.GET_IMAGE_HEIGHT() - row << " "
                  << std::flush;

        for (int column {}; column < Raytracer_camera.GET_IMAGE_WIDTH();
             column++)
        {
            Color pixel_color {0.0, 0.0, 0.0};

            for (int sample {}; sample <
                 Raytracer_camera.GET_SAMPLES_PER_PIXEL(); sample++)
            {
                Ray r {Raytracer_camera.cast_ray(column, row,
                                                 Raytracer_randomizer)};

                pixel_color += Raytracer_camera.ray_color(
                            r,
                            Raytracer_camera.GET_MAX_RAY_BOUNCE_DEPTH(),
                            Raytracer_world, Raytracer_randomizer,
                            Raytracer_material);

            } /* Cast rays at the pixel to sample the color and add it to
                 pixel_color */

            write_color(std::cout,
                        Raytracer_camera.GET_PIXEL_SAMPLE_SCALE() *
                        pixel_color);

        } /* Scan all the columns and write the color to the .ppm file */

    } /* Scan all the rows of the image */

    std::clog << "\r \nDone.  \n";

} /* Creates a .ppm image file using the member objects */