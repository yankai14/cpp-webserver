# My Web Server

This is a simple web server implemented in C++ to explore how low level socket programming works

## Features
Currently only support single threaded architecture. Will explore multithreaded architecture soon.

## TBD

1. Allow for user to handle response
2. Multithreaded design

## Requirements

- C++ compiler (supporting C++14)
- CMake (version 3.12 or higher)
- Dependencies: [list any external libraries or dependencies, if applicable]

## Installation

1. Clone the repository:
   ```shell
   git clone https://github.com/your-username/my-web-server.git
   cd my-web-server
   ```

2. Build the project using CMake:
    ```shell
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run the webserver
    ```shell
    ./cpp-webserver
    ```