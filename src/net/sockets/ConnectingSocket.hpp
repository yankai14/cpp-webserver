#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "BaseSocket.hpp"

namespace TransportLayer {
    class ConnectingSocket: public Socket {
        public:
            ConnectingSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr);
            int initConnection(int sock, struct sockaddr_in address) override;
    };
}

#endif