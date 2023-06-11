#ifndef BaseSocket_hpp
#define BaseSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace TransportLayer {
    class Socket {
        public:
            Socket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr);
            virtual int initConnection(int sock, struct sockaddr_in address) = 0;
            void testConnection(int item);
            struct sockaddr_in getAddress();
            int getSocket();
            int getConnection();
            void setConnection(int connection);

        private:
            int m_socket;
            int m_connection;
            struct sockaddr_in m_address;
    };
}

#endif