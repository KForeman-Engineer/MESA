# include "modules/PIDModule/include/PIDModel.hpp"
# include <iostream>
# include <random>

int main(){
    PIDModel model = PIDModel(1.0, 0.5, 0.3);
    double target = 6000;
    double measure = 0.0;
    double read = 0.0;

    model.SetTarget(target);
    for (size_t i = 0; i < target; i++)
    {

        read = model.Update(measure, 0.8);

        if(read >= target){
            printf("\nTARGET REACHED: %f", read);
            break;
        }

        if(read == 1.0){
            measure += 100.0;
        }
        else{
            measure += read;
        }

        printf("\nPID READ: %f", measure);
        
    }
    std::cin.get();
}