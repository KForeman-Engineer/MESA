// == MESA Required Interface for Core Modules

class ICore{
    public:
        virtual void Register() = 0;
        virtual void RecvCommand() = 0;
        virtual void SendCommand() = 0;
        virtual void Listen() = 0;
        virtual ~ICore() = default;
};

