//== PID Controller DEfinition Header File

#ifndef PIDCONTROLLER_HPP
#define PIDCONTROLLER_HPP


class PIDController{

    private:
        double kp, ki, kd;
        double target;
        double preverror;
        double intergral;

    public:
        // == Constructor 
        PIDController(double kp, double ki, double kd){
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
        }

        // == PID Functions
        void SetTarget(double tar);
        void Tune(double kp, double ki, double kd);
        double Update(double measure, double dt);

};

#endif