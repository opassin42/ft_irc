#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "../include/Server.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl;
        return 1;
    }

    try {
        int port = std::atoi(argv[1]);
        if (port <= 0 || port > 65535) {
            throw std::runtime_error("Invalid port number");
        }

        Server server(port, argv[2]);
        server.start();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}