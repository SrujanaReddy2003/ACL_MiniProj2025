#ifndef SERVER_HPP
#define SERVER_HPP
 
#include <string>
 
class Server {
public:
    virtual void start(const std::string& ip, int port) = 0;
    virtual ~Server() = default;
};
 
#endif
