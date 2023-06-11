#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>
#include "BaseSocket.hpp"

namespace TransportLayer {
    class BindingSocket: public Socket {
        public:
            BindingSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr);
            int initConnection(int sock, struct sockaddr_in address) override;
    };
}

#endif