

#ifndef PIDModel_HPP

#define PIDModel_HPP

namespace Models
{
    class PIDController{
        private:
            double p;
            double i;
            double d;
            double target;
            double inter;

        public:
            PIDController(double p, double i, double d);

            void SetTarget(double t); // == Sets Pid target
            void Refresh(double p, double i, double d); // == Refresh for new direction (Avoid messy readings)
            void Update(double measurement, double dt); // == Updates to calculate 

    };    
} // namespace Models



#endif