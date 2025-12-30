export module Color;

import std;

import Vector3D;

export class Color
{
    public:

        Color();

        Color(double initial_red, double initial_green,
              double initial_blue);

        Color(Vector3D&& initial_rgb);


        const Vector3D& GET_COLOR_RGB() const;
        

        double GET_RED_VALUE() const;

        double GET_GREEN_VALUE() const;

        double GET_BLUE_VALUE() const;


        Color& set_color(double red, double green, double blue);


        Color& operator +=(const Color& color_object);

        Color operator +(const Color& color_object) const;

        Color operator -(const Color& color_object) const;

        Color operator *(const Color& color_object) const;

        Color operator /(const Color& color_object) const;

        Color operator +(const Vector3D& vec3_object) const;

        Color operator -(const Vector3D& vec3_object) const;

        Color operator *(const Vector3D& vec3_object) const;

        Color operator /(const Vector3D& vec3_object) const;

        Color operator +(double added_amount) const;

        Color operator -(double subtracted_amount) const;

        Color operator *(double factor) const;

        Color operator /(double divisor) const;

    private:

        Vector3D Color_rgb;

}; /* Color - The color of the objects that have been hit by the Camera's
      rays. There is no alpha channel */


export Color operator+(double added_amount, const Color& color_object);

export Color operator-(double subtracted_amount,
                       const Color& color_object);

export Color operator*(double factor, const Color& color_object);

export Color operator/(double divisor, const Color& color_object);

export Color operator +(const Vector3D& vec3_object,
                        const Color& color_object);

export Color operator -(const Vector3D& vec3_object,
                        const Color& color_object);

export Color operator *(const Vector3D& vec3_object,
                        const Color& color_object);

export Color operator /(const Vector3D& vec3_object,
                        const Color& color_object);