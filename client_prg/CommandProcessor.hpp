#ifndef COMMAND_PROCESSOR_HPP
#define COMMAND_PROCESSOR_HPP 

#include <string>


class Client;

class CommandProcessor{
    Client& client;

public:

    explicit CommandProcessor(Client& client);
    void run(); 
    void listFiles();
    void copyFile(const std::string& source, const std::string& destination);
    void removeFile(const std::string& filename);
    void createFile(const std::string& filename);
    void readFile(const std::string& filename); 
};
 
#endif // COMMAND_PROCESSOR_HPP
