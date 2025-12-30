export module Interval;

export class Interval
{
    public:

        Interval();

        Interval(double initial_min, double initial_max);
        

        const double& GET_INTERVAL_MIN() const;

        const double& GET_INTERVAL_MAX() const;
        

        double size() const;

        
        bool contains(double value) const;

        bool surrounds(double value) const;

    private:

        double Interval_min {};

        double Interval_max {};

}; /* Interval - A range of values. */