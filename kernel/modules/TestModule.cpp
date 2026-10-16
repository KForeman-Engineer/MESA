# include "interface/IService.hpp"
# include <string>

class Test : public IService{
    public:
        // == Implement Functions
        void Listen() override{
            printf("Not Implemneted DO NOT USE");
        };

        void Register() override{
            printf("Not Implemtned DO NOT USE");
        };


        std::string PrintHello(){
            return "Hello world";
        }
};