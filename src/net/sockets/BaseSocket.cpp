#include "BaseSocket.hpp"


TransportLayer::Socket::Socket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr) {
    m_socket = socket(sinFamily, serviceType, protocol);

    m_address.sin_family = sinFamily;
    // Cannot just directly assign, need to convert to TCP/IP network byte order
    // https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-htons
    m_address.sin_port = htons(sinPort);
    m_address.sin_addr.s_addr = s_addr;
}


void TransportLayer::Socket::testConnection(int item) {
    if (item < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}


struct sockaddr_in TransportLayer::Socket::getAddress() {
    return m_address;
}


int TransportLayer::Socket::getSocket() {
    return m_socket;
}


int TransportLayer::Socket::getConnection() {
    return m_connection;
}


void TransportLayer::Socket::setConnection(int connection) {
    m_connection = connection;
}