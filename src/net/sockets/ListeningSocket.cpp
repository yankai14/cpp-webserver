#include "ListeningSocket.hpp"


TransportLayer::ListeningSocket::ListeningSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr, int backlog):
    BindingSocket(sinFamily, serviceType, protocol, sinPort, s_addr) {
        m_backlog = backlog;

}


void TransportLayer::ListeningSocket::startListening() {
    m_listening = listen(getSocket(), m_backlog);
    std::cout << "IsListening: " << std::endl;
}


bool TransportLayer::ListeningSocket::isListening() const {
    return m_listening;
}