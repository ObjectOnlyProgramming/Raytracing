module Interval;

import std;




Interval::Interval() :

Interval_min {std::numeric_limits<double>::infinity()},

Interval_max {-std::numeric_limits<double>::infinity()}

{

} /* Interval Default Constructor */


Interval::Interval(double initial_min, double initial_max) :

Interval_min {initial_min},

Interval_max {initial_max}

{

} /* Interval Parameter Constructor */




const double& Interval::GET_INTERVAL_MIN() const
{
    return Interval_min;

} /* Interval_min GETTER */

const double& Interval::GET_INTERVAL_MAX() const
{
    return Interval_max;

} /* Interval_max GETTER */




double Interval::size() const
{
    return Interval_max - Interval_min;

} /* Returns the size of the Interval */




bool Interval::contains(double value) const
{
    return Interval_min <= value && value <= Interval_max;

} /* Checks if the value is in the Interval's range */


bool Interval::surrounds(double value) const
{
    return Interval_min < value && value < Interval_max;

} /* Checks if the value is surrounded by the Interval's range */