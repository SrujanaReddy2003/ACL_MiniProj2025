#include "ServerTCP.hpp"
#include "CommandProcessor.hpp"
#include "Error.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
ServerTCP::ServerTCP(const std::string& ip, int port) {
    start(ip, port);
}
 
void ServerTCP::start(const std::string& ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << ERR_SOCKET_CREATION << std::endl;
        return;
    }
 
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);
 
    if (bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << ERR_BIND_FAILED << std::endl;
        close(sockfd);
        return;
    }
 
    listen(sockfd, 5);
    std::cout << "TCP Server running on " << ip << ":" << port << std::endl;
 
    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSock = accept(sockfd, (sockaddr*)&clientAddr, &clientLen);
 
        if (clientSock < 0) continue;
 
        char buffer[4096];
        while (true) {
            int bytesReceived = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
            if (bytesReceived <= 0) break;
 
            buffer[bytesReceived] = '\0';
            std::string msg = buffer;
 
             std::cout << "Received message: " << msg << std::endl;
 
 
            if (msg == "ping") {
                std::string response = "pong";
                send(clientSock, response.c_str(), response.size(), 0);
                continue;  // Skip processing other commands after ping
            }
 
            CommandProcessor processor;
            std::string response = processor.process(msg);
            send(clientSock, response.c_str(), response.size(), 0);
 
            if (msg == "exit") break;
        }
 
        close(clientSock);
    }
 
    close(sockfd);
}
