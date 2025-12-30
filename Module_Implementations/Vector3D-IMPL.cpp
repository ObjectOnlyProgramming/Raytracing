module Vector3D;

import std;




Vector3D::Vector3D() : Vector3D_array {0, 0, 0}
{

} /* Vector3D Default Constructor */


Vector3D::Vector3D(double initial_x, double initial_y, double initial_z) :

Vector3D_array {initial_x, initial_y, initial_z}

{

} /* Vector3D Parameter Constructor */




double Vector3D::GET_X_VALUE() const
{
    return Vector3D_array.at(0);

} /* Get the X value from Vector3D_array */


double Vector3D::GET_Y_VALUE() const
{
    return Vector3D_array.at(1);

} /* Get the Y value from Vector3D_array */


double Vector3D::GET_Z_VALUE() const
{
    return Vector3D_array.at(2);

} /* Get the Z value from Vector3D_array */




double Vector3D::length() const
{
    return std::sqrt(this->length_squared());

} /* Returns the length of the member variable */


double Vector3D::length_squared() const
{
    return this->Vector3D_array.at(0) * this->Vector3D_array.at(0) +
           this->Vector3D_array.at(1) * this->Vector3D_array.at(1) +
           this->Vector3D_array.at(2) * this->Vector3D_array.at(2);

} /* Squares the length of the member variable */


double Vector3D::dot(const Vector3D& another_Vector3D) const
{
    return Vector3D_array.at(0) * another_Vector3D.GET_X_VALUE() +
           Vector3D_array.at(1) * another_Vector3D.GET_Y_VALUE() +
           Vector3D_array.at(2) * another_Vector3D.GET_Z_VALUE();

} /* Vector3D dot product with another_Vector3D */




bool Vector3D::near_zero() const
{
    auto zero_limit {1e-8};

    return (std::fabs(Vector3D_array.at(0)) < zero_limit) &&
           (std::fabs(Vector3D_array.at(1)) < zero_limit) &&
           (std::fabs(Vector3D_array.at(2)) < zero_limit);

} /* Returns true if all the absolute values of a Vector3D are too close to zero */




void Vector3D::set_Vector3D_array(double x_value, double y_value,
                                  double z_value)
{
    Vector3D_array = {x_value, y_value, z_value};

} /* Set the member variable's X, Y and Z values */




Vector3D Vector3D::unit_vector() const
{
    return *this / this->length();

} /* Normalize this Vector3D */


Vector3D Vector3D::cross(const Vector3D& another_Vector3D)
{
    return Vector3D {Vector3D_array.at(1) * another_Vector3D.GET_Z_VALUE() -
                     Vector3D_array.at(2) * another_Vector3D.GET_Y_VALUE(),

                     Vector3D_array.at(2) * another_Vector3D.GET_X_VALUE() -
                     Vector3D_array.at(0) * another_Vector3D.GET_Z_VALUE(),

                     Vector3D_array.at(0) * another_Vector3D.GET_Y_VALUE() -
                     Vector3D_array.at(1) * another_Vector3D.GET_X_VALUE()};

} /* Vector3D cross product with another_Vector3D */


Vector3D Vector3D::reflect(const Vector3D& normal) const
{
    return *this - 2 * this->dot(normal) * normal;
    
} /* Handles mirrored light reflection (for metal materials) */


Vector3D Vector3D::refract(const Vector3D& normal, double etai_over_etat)
                           const
{
    auto cos_theta {std::fmin(-this->dot(normal), 1.0)};

    Vector3D r_out_perpendicular {etai_over_etat * (*this + cos_theta *
                                  normal)};

    Vector3D r_out_parallel {-std::sqrt(std::fabs(1.0 -
                             r_out_perpendicular.length_squared())) *
                             normal};

    return r_out_perpendicular + r_out_parallel;

} /* Handles light refraction (for glass, water, etc.) */




Vector3D Vector3D::operator -() const
{
    return Vector3D(-Vector3D_array.at(0), -Vector3D_array.at(1),
                    -Vector3D_array.at(2));

} /* Negative Vector3D */


Vector3D& Vector3D::operator +=(const Vector3D& input_vec3)
{
    Vector3D_array.at(0) += input_vec3.GET_X_VALUE();

    Vector3D_array.at(1) += input_vec3.GET_Y_VALUE();

    Vector3D_array.at(2) += input_vec3.GET_Z_VALUE();

    return *this;

} /* Vector3D += Vector3D */


Vector3D& Vector3D::operator *=(double factor)
{
    Vector3D_array.at(0) *= factor;

    Vector3D_array.at(1) *= factor;

    Vector3D_array.at(2) *= factor;

    return *this;

} /* Vector3D *= double */


Vector3D& Vector3D::operator /=(double divisor)
{
    return *this *= 1 / divisor;

} /* Vector3D /= double */


Vector3D Vector3D::operator +(const Vector3D& second_vec3) const
{
    return Vector3D(this->GET_X_VALUE() + second_vec3.GET_X_VALUE(),
                    this->GET_Y_VALUE() + second_vec3.GET_Y_VALUE(),
                    this->GET_Z_VALUE() + second_vec3.GET_Z_VALUE());

} /* Vector3D + Vector3D */


Vector3D Vector3D::operator -(const Vector3D& second_vec3) const
{
    return Vector3D(this->GET_X_VALUE() - second_vec3.GET_X_VALUE(),
                    this->GET_Y_VALUE() - second_vec3.GET_Y_VALUE(),
                    this->GET_Z_VALUE() - second_vec3.GET_Z_VALUE());

} /* Vector3D - Vector3D */


Vector3D Vector3D::operator *(const Vector3D& second_vec3) const
{
    return Vector3D(this->GET_X_VALUE() * second_vec3.GET_X_VALUE(),
                    this->GET_Y_VALUE() * second_vec3.GET_Y_VALUE(),
                    this->GET_Z_VALUE() * second_vec3.GET_Z_VALUE());

} /* Vector3D * Vector3D */


Vector3D Vector3D::operator /(const Vector3D& second_vec3) const
{
    return Vector3D(this->GET_X_VALUE() / second_vec3.GET_X_VALUE(),
                    this->GET_Y_VALUE() / second_vec3.GET_Y_VALUE(),
                    this->GET_Z_VALUE() / second_vec3.GET_Z_VALUE());

} /* Vector3D / Vector3D */


Vector3D Vector3D::operator +(double added_amount) const
{
    return Vector3D(this->GET_X_VALUE() + added_amount,
                    this->GET_Y_VALUE() + added_amount,
                    this->GET_Z_VALUE() + added_amount);
                    
} /* Vector3D + double */


Vector3D Vector3D::operator -(double subtracted_amount) const
{
    return Vector3D(this->GET_X_VALUE() - subtracted_amount,
                    this->GET_Y_VALUE() - subtracted_amount,
                    this->GET_Z_VALUE() - subtracted_amount);

} /* Vector3D - double */


Vector3D Vector3D::operator *(double factor) const
{
    return Vector3D(this->GET_X_VALUE() * factor,
                    this->GET_Y_VALUE() * factor,
                    this->GET_Z_VALUE() * factor);

} /* Vector3D * double */


Vector3D Vector3D::operator /(double divisor) const
{
    return Vector3D(this->GET_X_VALUE() / divisor,
                    this->GET_Y_VALUE() / divisor,
                    this->GET_Z_VALUE() / divisor);

} /* Vector3D / double */


Vector3D operator +(double amount_to_add, const Vector3D vec3_object)
{
    return vec3_object + amount_to_add;

} /* double + Vector3D */


Vector3D operator -(double amount_to_subtract, const Vector3D vec3_object)
{
    return vec3_object - amount_to_subtract;

} /* double - Vector3D */


Vector3D operator *(double factor, const Vector3D vec3_object)
{
    return vec3_object * factor;

} /* double * Vector3D */


Vector3D operator /(double divisor, const Vector3D vec3_object)
{
    return 1 / divisor * vec3_object;

} /* double / Vector3D */


std::ostream& operator <<(std::ostream& output,
                          const Vector3D& vec3_to_output)
{
    return output << vec3_to_output.GET_X_VALUE() << " "
                  << vec3_to_output.GET_Y_VALUE() << " "
                  << vec3_to_output.GET_Z_VALUE();

} /* std::cout << Vector3D */
