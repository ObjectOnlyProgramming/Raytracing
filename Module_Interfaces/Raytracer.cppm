export module Raytracer;


import std;

import Vector3D;

import Randomizer;

import Color;

import Sphere;

import Hittable;

import HittableList;

import Camera;

import Material;


export class Raytracer
{
    public:

        Raytracer(int initial_image_width, double initial_aspect_ratio,
                  int initial_samples_per_pixel,
                  double initial_vertical_field_of_view,
                  double initial_focus_distance,
                  Vector3D intial_look_from, Vector3D initial_look_at,
                  Vector3D initial_up_vector,
                  double initial_defocus_angle,
                  int initial_max_raybounce_depth);

    private:

        Raytracer();


        int Raytracer_image_width {};

        double Raytracer_aspect_ratio {};

        int Raytracer_samples_per_pixel {};

        double Raytracer_vertical_field_of_view {};

        double Raytracer_focus_distance {};


        Vector3D Raytracer_look_from {};

        Vector3D Raytracer_look_at {};

        Vector3D Raytracer_up_vector {};


        double Raytracer_defocus_angle {};

        int Raytracer_max_raybounce_depth {};


        Randomizer Raytracer_randomizer;


        HittableList Raytracer_world {Raytracer_randomizer};


        Camera Raytracer_camera {Raytracer_image_width,
                                 Raytracer_aspect_ratio,
                                 Raytracer_samples_per_pixel,
                                 Raytracer_vertical_field_of_view,
                                 Raytracer_focus_distance,
                                 Raytracer_look_from, Raytracer_look_at,
                                 Raytracer_up_vector,
                                 Raytracer_defocus_angle,
                                 Raytracer_max_raybounce_depth,
                                 Raytracer_world};


        std::shared_ptr<Material> Raytracer_material;


        double linear_to_gamma(double linear_component);

        
        void write_color(std::ostream& output, const Color& pixel_color);

        void render();

}; /* Raytracer - A program that simulates real-world lighting in a given scene */