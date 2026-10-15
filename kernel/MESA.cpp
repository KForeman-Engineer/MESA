// == Kernel Wrapper (Glues everything Together)
# include "modules/Controller/PIDController.hpp"
#include <iostream>
#include <iomanip>



int main(){
    PIDController controller = PIDController(0.0, 0.0, 0.0);
    double dt = 0.1;
    double pv = 0.0;
    double heating = 0.0;
    double cooling = 0.0;
    double out = 0.0;
    int end = 0;

    controller.SetTarget(100.0);
    controller.Tune(5.0, 0.2, 0.0);
    for (int i = 0; i <= 1000; i++){
        out = controller.Update(pv, dt);

        // Print current state
        cooling = (pv - 20.0) * 0.02; 
        heating = out * 0.15;        
        pv += (heating - cooling) * dt;
        printf("Current PV: %f\n", out);
    }
    std::cin >> end;
    return 0;

}