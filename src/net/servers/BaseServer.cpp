#include "BaseServer.hpp"


ApplicationLayer::BaseServer::BaseServer(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr, int backlog) {
    m_listeningSocket = new TransportLayer::ListeningSocket(sinFamily, serviceType, protocol, sinPort, s_addr, backlog);
    m_listeningSocket->startListening();
}


TransportLayer::ListeningSocket* ApplicationLayer::BaseServer::getListeningSocket() {
    return m_listeningSocket;
}


ApplicationLayer::BaseServer::~BaseServer() {
    delete m_listeningSocket;
}

namespace ApplicationLayer {
    volatile sig_atomic_t g_stopSignal = 0;
}