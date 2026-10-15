// == PID Controller Implementation File
#include "PIDController.hpp"
#include <iostream>
#include <algorithm>



// == Sets the PID Controllers target
void PIDController::SetTarget(double tar){

    if(tar == 0){
        return;
    }
    target = tar;
};

// == Update the PID Controller and perform Calculations
double PIDController::Update(double measure, double dt){

    // == Calculate Error Between target and measurement
    double error = target - measure;
    // == Add to Intergral (Ensure it does not go over -1.0 to 1.0)
    intergral += std::clamp(error * dt, -1.0, 1.0);
    // == Calculate the Change between the error
    double der = (error - preverror) / dt;
    // == Set Prev Error
    preverror = error;

    printf("Current error: %f\n", error);

    double out = (kp * error) + (ki * intergral) + (kd * der);
    return out;
};


// == Tunes the PID controller for desirered results
void PIDController::Tune(double kp, double ki, double kd){
    if(kp == 0 &&  ki == 0 && kd == 0){
        return;
    }
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
};