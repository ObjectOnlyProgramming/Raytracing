module HitRecord;

import Ray;

import Vector3D;




HitRecord::HitRecord()
{

} /* HitRecord Default Constructor */



const Vector3D& HitRecord::GET_P() const
{
    return HitRecord_p;

} /* HitRecord_p GETTER */

const Vector3D& HitRecord::GET_NORMAL() const
{
    return HitRecord_normal;

} /* HitRecord_normal GETTER */




const double& HitRecord::GET_T_VALUE() const
{
    return HitRecord_t_value;

} /* HitRecord_t_value GETTER */




const bool& HitRecord::GET_FRONT_FACE() const
{
    return HitRecord_front_face;

} /* HitRecord_front_face GETTER */




void HitRecord::set_p(const Vector3D& new_p_value)
{
    HitRecord_p = new_p_value;

} /* HitRecord_p setter */


void HitRecord::set_normal(const Vector3D& new_normal_value)
{
    HitRecord_normal = new_normal_value;

} /* HitRecord_normal setter */


void HitRecord::set_t_value(double new_t_value)
{
    HitRecord_t_value = new_t_value;

} /* HitRecord_t_value setter */


void HitRecord::set_face_normal(const Ray& r,
                                const Vector3D& outward_normal)
{
    /* Sets the hit record normal. The "outward_normal" parameter is
       expected to be a unit_vector */ 

    HitRecord_front_face = r.Ray_direction_dot_product_with(outward_normal) < 0;

    HitRecord_normal = HitRecord_front_face ?
                       outward_normal : -outward_normal;

} /* Set the normal value to use to record a hit */