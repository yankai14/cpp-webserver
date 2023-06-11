#ifndef SynchronousServer_hpp
#define SynchronousServer_hpp

#include <csignal>
#include "BaseServer.hpp"


namespace ApplicationLayer {
    class SynchronousServer: public BaseServer {
        public:
            SynchronousServer();
            void launch();
        private:
            void accepter() override;
            void handler() override;
            void responder() override;
            static void handleSIGINT(int signal);

            char buffer[30000];
            int m_socket;
    };
}

#endif