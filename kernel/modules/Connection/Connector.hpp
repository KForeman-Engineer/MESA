// == Connector Class Definitions to be called from MESA.cpp

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

class Connector{

    private:
        std::string connname;
        int dport;
        int sport;
        char conn; // == TODO: Fix to Actually Contain Connection


    public:
        Connector(std::string ConnName, int DataPort, int StreamPort){
            connname = ConnName;
            dport = DataPort;
            sport = StreamPort;
        };

        void Establish(); // == Connects to the KRPC API via the provied information during Class Construction
        void ReConnect(); // == Uses the dport to Reconnect if Disconnected (MAX: 3 Retries before ABORT)
};

#endif

