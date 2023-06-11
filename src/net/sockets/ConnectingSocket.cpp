#include "ConnectingSocket.hpp"


TransportLayer::ConnectingSocket::ConnectingSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr):
    Socket(sinFamily, serviceType, protocol, sinPort, s_addr) {
        int sock = getSocket();
        struct sockaddr_in address = getAddress();
        int connection = initConnection(sock, address);
        setConnection(connection);
        testConnection(connection);
}


int TransportLayer::ConnectingSocket::initConnection(int sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}