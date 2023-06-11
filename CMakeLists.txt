cmake_minimum_required(VERSION 3.12)
project(cpp-webserver)

set(CMAKE_CXX_STANDARD 11)

# Add your source files
set(SOURCES
    src/net/sockets/BaseSocket.cpp
    src/net/sockets/BindingSocket.cpp
    src/net/sockets/ConnectingSocket.cpp
    src/net/sockets/ListeningSocket.cpp
    
    src/net/servers/BaseServer.cpp
    src/net/servers/SynchronousServer.cpp
    src/net/servers/main.cpp
)

# Add your include directories
include_directories(src)

# Create an executable
add_executable(cpp-webserver ${SOURCES})