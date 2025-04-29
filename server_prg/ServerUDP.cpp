// ServerUDP.cpp
#include "ServerUDP.hpp"
#include "CommandProcessor.hpp"
#include "Error.hpp"
#include "Success.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
ServerUDP::ServerUDP(const std::string& ip, int port) {
    start(ip, port);
}
 
void ServerUDP::start(const std::string& ip, int port) {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return;
    }
 
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    servaddr.sin_port = htons(port);
 
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(sockfd);
        return;
    }
 
    std::cout << "UDP Server listening on " << ip << ":" << port << std::endl;
 
    socklen_t len;
    while (true) {
        len = sizeof(cliaddr);
        ssize_t n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                             (struct sockaddr*)&cliaddr, &len);
        if (n < 0) {
            perror("recvfrom error");
            continue;
        }
 
        buffer[n] = '\0';
        std::string msg(buffer);
 
        std::cout << "Received message: " << msg << std::endl;
 
        // Check for ping message
        if (msg == "ping") {
            std::string response = "pong";
            sendto(sockfd, response.c_str(), response.length(), 0,
                   (struct sockaddr*)&cliaddr, len);
            continue; // Skip processing further commands after ping
        }
 
 
        CommandProcessor processor;
        std::string response = processor.process(msg);
 
        sendto(sockfd, response.c_str(), response.length(), 0,
               (struct sockaddr*)&cliaddr, len);
 
        if (response == "SHUTDOWN") {
            std::cout << "Shutting down UDP server..." << std::endl;
            break;
        }
    }
 
    close(sockfd);
}
