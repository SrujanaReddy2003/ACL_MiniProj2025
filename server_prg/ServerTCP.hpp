#ifndef SERVERTCP_HPP
#define SERVERTCP_HPP
 
#include "Server.hpp"
 
class ServerTCP : public Server {
public:
    ServerTCP(const std::string& ip, int port);
    void start(const std::string& ip, int port) override;
};
 
#endif
