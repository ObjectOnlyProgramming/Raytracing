export module Vector3D;

import std;

export class Vector3D
{
    public:

        Vector3D();

        Vector3D(double initial_x, double initial_y, double initial_z);


        double GET_X_VALUE() const;

        double GET_Y_VALUE() const;

        double GET_Z_VALUE() const;


        double length() const;

        double length_squared() const;

        double dot(const Vector3D& vec3_dot_product) const;


        bool near_zero() const;


        void set_Vector3D_array(double value1, double value2,
                                double value3);


        Vector3D unit_vector() const;

        Vector3D cross(const Vector3D& vec3_cross_product);

        Vector3D reflect(const Vector3D& normal) const;

        Vector3D refract(const Vector3D& normal, double etai_over_etat) const;


        Vector3D operator -() const;

        Vector3D& operator +=(const Vector3D& input_vec3);

        Vector3D& operator *=(double factor);

        Vector3D& operator /=(double divisor);

        Vector3D operator +(const Vector3D& second_vec3) const;

        Vector3D operator -(const Vector3D& second_vec3) const;

        Vector3D operator *(const Vector3D& second_vec3) const;

        Vector3D operator /(const Vector3D& second_vec3) const;

        Vector3D operator +(double added_amount) const;

        Vector3D operator -(double subtracted_amount) const;

        Vector3D operator *(double factor) const;

        Vector3D operator /(double divisor) const;

    private:

        std::array<double, 3> Vector3D_array;

}; /* Vector3D - Vectors with X, Y, Z values */


export Vector3D operator +(double amount_to_add,
                           const Vector3D vec3_object);

export Vector3D operator -(double amount_to_subtract,
                           const Vector3D vec3_object);

export Vector3D operator *(double factor, const Vector3D vec3_object);

export Vector3D operator /(double divisor, const Vector3D vec3_object);

export std::ostream& operator <<(std::ostream& output,
                                 const Vector3D& vec3_to_output);