module Color;

import std;

import Vector3D;

import Interval;




Color::Color()
{

} /* Color Default Constructor */


Color::Color(double initial_red, double initial_green, double initial_blue)
{
    this->set_color(initial_red, initial_green, initial_blue);

} /* Color Parameter Constructor */


Color::Color(Vector3D&& initial_rgb) :

Color_rgb {initial_rgb}

{
    
} /* Color Vector3D Constructor */



const Vector3D& Color::GET_COLOR_RGB() const
{
    return Color_rgb;

} /* Color_rgb GETTER */




double Color::GET_RED_VALUE() const
{
    return Color_rgb.GET_X_VALUE();

} /* Get the Color_rgb red value */

double Color::GET_GREEN_VALUE() const
{
    return Color_rgb.GET_Y_VALUE();

} /* Get the Color_rgb green value */

double Color::GET_BLUE_VALUE() const
{
    return Color_rgb.GET_Z_VALUE();

} /* Get the Color_rgb blue value */








Color& Color::set_color(double red, double green, double blue)
{
    Color_rgb.set_Vector3D_array(red, green, blue);

    return *this;

} /* void Color::set_color(double red, double green, double blue) */




Color& Color::operator +=(const Color& color_object)
{
    this->Color_rgb += color_object.GET_COLOR_RGB();

    return *this;

} /* Color += Color */


Color Color::operator +(const Color& color_object) const
{
    return Color(this->Color_rgb + color_object.GET_COLOR_RGB());

} /* Color + Color */


Color Color::operator -(const Color& color_object) const
{
    return Color(this->Color_rgb - color_object.GET_COLOR_RGB());

} /* Color - Color */


Color Color::operator *(const Color& color_object) const
{
    return Color(this->Color_rgb * color_object.GET_COLOR_RGB());

} /* Color * Color */


Color Color::operator /(const Color& color_object) const
{
    return Color(this->Color_rgb / color_object.GET_COLOR_RGB());

} /* Color / Color */


Color Color::operator +(const Vector3D& vector3D_object) const
{
    return Color(this->Color_rgb + vector3D_object);

} /* Color + Vector3D */


Color Color::operator -(const Vector3D& vector3D_object) const
{
    return Color(this->Color_rgb - vector3D_object);

} /* Color - Vector3D */


Color Color::operator *(const Vector3D& vector3D_object) const
{
    return Color(this->Color_rgb * vector3D_object);

} /* Color * Vector3D */


Color Color::operator /(const Vector3D& vector3D_object) const
{
    return Color(this->Color_rgb / vector3D_object);

} /* Color / Vector3D */


Color Color::operator +(double added_amount) const
{
    return Color(this->Color_rgb + added_amount);

} /* Color + double */


Color Color::operator -(double subtracted_amount) const
{
    return Color(this->Color_rgb - subtracted_amount);

} /* Color - double */


Color Color::operator *(double factor) const
{
    return Color(this->Color_rgb * factor);

} /* Color * double */


Color Color::operator /(double divisor) const
{
    return Color(this->Color_rgb / divisor);

} /* Color / double */


Color operator +(double added_amount, const Color& color_object)
{
    return color_object + added_amount;

} /* double + Color */


Color operator -(double subtracted_amount, const Color& color_object)
{
    return color_object - subtracted_amount;

} /* double - Color */


Color operator *(double factor, const Color& color_object)
{
    return color_object * factor;

} /* double * Color */


Color operator /(double divisor, const Color& color_object)
{
    return color_object / divisor;

} /* double / Color */


Color operator +(const Vector3D& vec3_object, const Color& color_object)
{
    return color_object + vec3_object;

} /* Vector3D + Color */


Color operator -(const Vector3D& vec3_object, const Color& color_object)
{
    return color_object - vec3_object;

} /* Vector3D - Color */


Color operator *(const Vector3D& vec3_object, const Color& color_object)
{
    return color_object * vec3_object;

} /* Vector3D * Color */


Color operator /(const Vector3D& vec3_object, const Color& color_object)
{
    return color_object / vec3_object;

} /* Vector3D / Color */