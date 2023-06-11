#ifndef ListingSocket_hpp
#define ListingSocket_hpp

#include <stdio.h>
#include "BindingSocket.hpp"


namespace TransportLayer {
    class ListeningSocket: public BindingSocket {
        public:
            ListeningSocket(int sinFamily, int serviceType, int protocol, int sinPort, u_long s_addr, int backlog);
            void startListening();
            bool isListening() const;
        private:
            int m_backlog;
            int m_listening;
    };
}

#endif