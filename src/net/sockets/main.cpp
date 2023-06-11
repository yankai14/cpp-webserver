#include "Sockets.hpp"


int main () {
    std::cout << "Starting" << std::endl;
    std::cout << "Listening Socket" << std:: endl;
    TransportLayer::ListeningSocket ls = TransportLayer::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    std::cout << "Success" << std::endl;
}