#include <unistd.h>
#include "SynchronousServer.hpp"


ApplicationLayer::SynchronousServer::SynchronousServer() :
    BaseServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
        struct sigaction sigIntHandler;
        sigIntHandler.sa_handler = handleSIGINT;
        sigemptyset(&sigIntHandler.sa_mask);
        sigIntHandler.sa_flags = 0;
        sigaction(SIGINT, &sigIntHandler, nullptr);
        launch();
    }


void ApplicationLayer::SynchronousServer::accepter() {
    TransportLayer::ListeningSocket* ls = getListeningSocket();
    struct sockaddr_in address = ls->getAddress();
    int addrlen = sizeof(address);
    m_socket = accept(ls->getSocket(), (struct sockaddr *)&address, (socklen_t*)&addrlen);
    
    read(m_socket, buffer, 30000);
}


void ApplicationLayer::SynchronousServer::handler() {
    std::cout << buffer << std::endl;
}


void ApplicationLayer::SynchronousServer::responder() {
    std::string response = "Responded";
    write(m_socket, response.c_str(), response.size());
    close(m_socket);
}


void ApplicationLayer::SynchronousServer::handleSIGINT(int signal) {
    g_stopSignal = 1;
}


void ApplicationLayer::SynchronousServer::launch() {
    while(!g_stopSignal) {
        std::cout << "======= Waiting =======" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "====== Done ========" << std::endl;
    }

    std::cout << "Server is shutting down..." << std::endl;
    // Cleanup code here
    std::cout << "Server has been stopped." << std::endl;
}