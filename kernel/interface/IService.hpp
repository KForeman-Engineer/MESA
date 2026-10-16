// == MESA Service for Plugins

class IService{
    
    public:
        virtual void Listen() = 0; // == Listens to events from the Bus
        virtual void Register() = 0; // == Registers the Module to the Registry
        virtual ~IService() = default; // == Deconstructor
};