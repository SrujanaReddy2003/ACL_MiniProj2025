#ifndef CLIENT_TCP_HPP
#define CLIENT_TCP_HPP

#include "Client.hpp"
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

 
class ClientTCP : public Client {
public:
    ClientTCP(const std::string& ip, int port);
 
    void sendMessage(const std::string& message, std::string& response) override;
    void run() override;
    bool checkConnection();
 
    private:
    int sockfd;
    struct sockaddr_in serverAddr;
};
 
#endif // CLIENT_TCP_HPP
