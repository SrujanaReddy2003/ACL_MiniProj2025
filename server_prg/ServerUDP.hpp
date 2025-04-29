#ifndef SERVER_UDP_HPP
#define SERVER_UDP_HPP
 
#include "Server.hpp"
 
class ServerUDP : public Server {
public:
    ServerUDP(const std::string& ip, int port);
    void start(const std::string& ip, int port) override; // Change 'run()' to 'start()'
};
 
#endif // SERVER_UDP_HPP
