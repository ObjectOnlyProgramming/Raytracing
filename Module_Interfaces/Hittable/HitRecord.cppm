export module HitRecord;

import std;

import Ray;

import Vector3D;


export class HitRecord
{
    public:

        HitRecord();

        
        const Vector3D& GET_P() const;

        const Vector3D& GET_NORMAL() const;


        const double& GET_T_VALUE() const;


        const bool& GET_FRONT_FACE() const;


        void set_face_normal(const Ray& r, const Vector3D& outward_normal);

        void set_p(const Vector3D& new_p_value);

        void set_normal(const Vector3D& new_normal_value);

        void set_t_value(double new_t_value);

    private:

        Vector3D HitRecord_p;

        Vector3D HitRecord_normal;


        double HitRecord_t_value {};

        
        bool HitRecord_front_face {};

}; /* HitRecord - Records the hit from the ray and where it hit the object */
