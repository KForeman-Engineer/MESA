# include "include/PIDModel.hpp"
# include <iostream>
# include <algorithm>


    double PIDModel::Update(double measure, double dt){

        // == Calculates the Error
        double err = Tar - measure;
        // == Assign the Intergral
        Inter += err * dt;
        // == Calc Determinate
        double der = (err - PrevErr) / dt; 
        PrevErr = err;

        double out = (Kp * err) + (Ki * Inter) + (Kd * der);

        return std::clamp(out, -1.0, 1.0);

    };

    void PIDModel::Refresh(double p, double i, double d){
        // == TODO: Add Check to ensure Values are Correct
        Kp = p;
        Ki = i;
        Kd = d;
    };

    void PIDModel::SetTarget(double Target){
        if(Target == 0){
            return;
        }

        Tar = Target;
    };