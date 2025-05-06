#include "ClientTCP.hpp"
#include "CommonMessages.hpp"
#include "CommandProcessor.hpp"
#include "CommonHeader.hpp"
 
 
ClientTCP::ClientTCP(const std::string& ip, int port) : Client(ip, port) {}
void ClientTCP::sendMessage(const std::string& message, std::string& response) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        response = ERR_SOCKET_CREATION;
        return;
    }
 
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr);
 
    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        response = ERR_CONNECTION_FAILED;
        close(sock);
        return;
    }
 
    send(sock, message.c_str(), message.size(), 0);
 
    char buffer[4096];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        response = buffer;
    }
 
 
    close(sock);
}
 
void ClientTCP::run() {
    CommandProcessor processor(*this);
    processor.run();
}
 
bool ClientTCP::checkConnection() {
    std::string response;
    sendMessage("ping", response);
 
    return response == "pong";
}
