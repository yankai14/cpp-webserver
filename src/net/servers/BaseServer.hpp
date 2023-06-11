#ifndef BaseServer_hpp
#define BaseServer_hpp

#include "../Networking.hpp"

namespace ApplicationLayer {
    class BaseServer {
    private:
        TransportLayer::ListeningSocket* m_listeningSocket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

    public:
        BaseServer(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr, int backlog);
        virtual ~BaseServer();
        virtual void launch() = 0;
        TransportLayer::ListeningSocket* getListeningSocket();
    };

    extern volatile sig_atomic_t g_stopSignal;
}

#endif