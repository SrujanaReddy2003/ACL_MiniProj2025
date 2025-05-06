#ifndef SERVER_COMMANDPROCESSOR_HPP
#define SERVER_COMMANDPROCESSOR_HPP
 
#include <string>
 
 std::string handleRemove(const std::string& file);class CommandProcessor {
public:
    std::string process(const std::string& message);
 
private:
    std::string handleList(const std::string& dir);
    std::string handleRead(const std::string& file);
    std::string handleCreate(const std::string& file);
    std::string handleCopy(const std::string& src, const std::string& dest);
    std::string handleRemove(const std::string& file);
};

 
#endif // SERVER_COMMANDPROCESSOR_HPP
