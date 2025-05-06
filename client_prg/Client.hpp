#ifndef CLIENT_HPP
#define CLIENT_HPP
 
#include <string>
 
class Client {
// protected so that only ClientTCP and CLientUDP (both are child classes of client) can access and modify ip and port
protected:
	std::string ip;
    int port;
 
public:
    Client(const std::string& ip, int port) : ip(ip), port(port) {}
    virtual ~Client() = default;
 
    // Sends a message to the server and gets a response
    virtual void sendMessage(const std::string& message, std::string& response) = 0;
 
    // Starts the interactive session
    virtual void run() = 0;
};
 
#endif // CLIENT_HPP
