#include "CommandProcessor.hpp"
#include "Client.hpp"
#include "CommonHeader.hpp"



CommandProcessor::CommandProcessor(Client& client) : client(client) {}

void CommandProcessor::run() {
    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "-ls") {
            listFiles();
        } else if (command == "-cp") {
            std::string src, dst;
            std::cout << "Enter source file path: ";
            std::getline(std::cin, src);
            std::cout << "Enter destination file path: ";
            std::getline(std::cin, dst);
            copyFile(src, dst);
        } else if (command == "-rm") {
            std::string file;
            std::cout << "Enter file path to remove: ";
            std::getline(std::cin, file);
            removeFile(file);
        } else if (command == "-cr") {
            std::string file;
            std::cout << "Enter file path to create: ";
            std::getline(std::cin, file);
            createFile(file);
        } else if (command == "-re") {
            std::string file;
            std::cout << "Enter file path to read it: ";
            std::getline(std::cin, file);
            readFile(file);
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}

void CommandProcessor::listFiles() {
    std::string directory;
    std::cout << "Enter directory path (or press Enter for current directory): ";
    std::getline(std::cin, directory);
    if (directory.empty()) directory = ".";

    std::string request = "-ls " + directory;
    std::string response;
    client.sendMessage(request, response);
    std::cout << "Server response:\n\n" << response << std::endl;
}

void CommandProcessor::copyFile(const std::string& src, const std::string& dst) {
    std::string request = "-cp " + src + " " + dst;
    std::string response;
    client.sendMessage(request, response);
    std::cout << "Server response: " << response << std::endl;
}

void CommandProcessor::removeFile(const std::string& filePath) {
    std::string request = "-rm " + filePath;
    std::string response;
    client.sendMessage(request, response);
    std::cout << "Server response: " << response << std::endl;
}

void CommandProcessor::createFile(const std::string& filePath) {
    std::string request = "-cr " + filePath;
    std::string response;
    client.sendMessage(request, response);
    std::cout << "Server response: " << response << std::endl;
}

void CommandProcessor::readFile(const std::string& filePath) {
    std::string request = "-re " + filePath;
    std::string response;
    client.sendMessage(request, response);
    std::cout << "Server response: " << response << std::endl;
}

