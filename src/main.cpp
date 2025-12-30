import Vector3D;

import Raytracer;


int main()
{
    Raytracer object_only_raytracer {

                    400,                        // Image width
                    16.0 / 9.0,                 // Aspect ratio
                    100,                        // Samples per pixel
                    20.0,                       // Vertical field of view
                    10.0,                       // Focus distance
                    Vector3D(13.0, 2.0, 3.0),   // Camera look from
                    Vector3D(0.0, 0.0, 0.0),    // Camera look at
                    Vector3D(0.0, 1.0, 0.0),    // Up vector
                    0.6,                        // Defocus angle
                    10                          // Max ray bounce depth
                };

} /* main */