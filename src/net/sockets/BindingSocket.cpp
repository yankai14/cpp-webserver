#include "BindingSocket.hpp"


TransportLayer::BindingSocket::BindingSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr):
    Socket(sinFamily, serviceType, protocol, sinPort, s_addr) {
        int sock = getSocket();
        struct sockaddr_in address = getAddress();
        int connection = initConnection(sock, address);
        std::cout << "Connection: " << connection << std::endl;
        std::cout << "Socket: " << sock << std::endl;
        setConnection(connection);
        testConnection(connection);
}


int TransportLayer::BindingSocket::initConnection(int sock, struct sockaddr_in address) {
    int result = bind(sock, (struct sockaddr *)&address, sizeof(address));
    if (result == -1) {
        perror("Failed to bind");
        std::cout << "Error code: " << errno << std::endl;
        std::cout << "Error description: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    return result;
}
