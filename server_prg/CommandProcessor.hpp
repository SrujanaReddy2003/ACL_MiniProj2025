#ifndef SERVER_COMMANDPROCESSOR_HPP
#define SERVER_COMMANDPROCESSOR_HPP
 
#include <string>
 
class CommandProcessor {
public:
    std::string process(const std::string& message);
 
private:
    std::string handleList(const std::string& dir);
    std::string handleRead(const std::string& file);
    std::string handleCreate(const std::string& file);
    std::string handleRemove(const std::string& file);
};
 
#endif // SERVER_COMMANDPROCESSOR_HPP
