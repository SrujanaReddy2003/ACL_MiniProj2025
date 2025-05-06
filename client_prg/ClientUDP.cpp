#include "ClientUDP.hpp"
#include "CommonMessages.hpp"
#include "CommandProcessor.hpp"
#include "CommonHeader.hpp"
 
ClientUDP::ClientUDP(const std::string& ip, int port) : Client(ip, port) {}
 
 
void ClientUDP::sendMessage(const std::string& message, std::string& response) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        response = ERR_SOCKET_CREATION;
        return;
    }
 
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
 
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr);
 
    sendto(sock, message.c_str(), message.size(), 0, (sockaddr*)&server_addr, sizeof(server_addr));
 
    char buffer[4096];
    sockaddr_in from_addr{};
    socklen_t from_len = sizeof(from_addr);
 
    int bytes_received = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&from_addr, &from_len);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        response = buffer;
    } else {
        response = ERR_CONNECTION_FAILED;
    }
 
    close(sock);
}
 
void ClientUDP::run() {
    CommandProcessor processor(*this);
    processor.run();
}
 
 
bool ClientUDP::checkConnection() {
    std::string response;
    sendMessage("ping", response);
 
    return response == "pong";
}
