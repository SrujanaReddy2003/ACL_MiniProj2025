#include "CommandProcessor.hpp"
#include "Error.hpp"
#include "Success.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
namespace fs = std::filesystem;
 
std::string CommandProcessor::process(const std::string& message) {
    if (message == "ping") return SUCCESS_CONNECTED;
 
    if (message.find("-ls") == 0) {
        std::string dir = message.substr(3);
        return handleList(dir);
    }
 
    if (message.find("-read") == 0) {
        std::string file = message.substr(5);
        return handleRead(file);
    }
 
    if (message.find("-create") == 0) {
        std::string file = message.substr(8);
        return handleCreate(file);
    }
 
    if (message.find("-rm") == 0) {
        std::string file = message.substr(4);
        return handleRemove(file);
    }
 
    return ERR_INVALID_COMMAND;
}
 
std::string CommandProcessor::handleList(const std::string& inputDir) {
    std::string dir = inputDir;
    dir.erase(0, dir.find_first_not_of(" \t\n\r"));
    dir.erase(dir.find_last_not_of(" \t\n\r") + 1);
 
    if(dir == "/root"){
            return ERR_DIR_NOT_FOUND;
    }
 
 
    if (!dir.empty() && dir[0] == '~') {
        const char* home = std::getenv("HOME");
        if (home) dir = std::string(home) + dir.substr(1);
    }
 
    if (dir.empty()) dir = fs::current_path().string();
 
    if (!fs::exists(dir) || !fs::is_directory(dir)) return ERR_DIR_NOT_FOUND;
 
    std::string result;
    for (const auto& entry : fs::directory_iterator(dir)) {
        result += entry.path().filename().string() + "\n";
    }
    return result;
}
 
std::string CommandProcessor::handleRead(const std::string& file) {
    std::string path = file;
    path.erase(0, path.find_first_not_of(" \t\n\r"));
    path.erase(path.find_last_not_of(" \t\n\r") + 1);
     if (!path.empty() && path[0] == '~') {
        const char* home = std::getenv("HOME");
        if (home) path = std::string(home) + path.substr(1);
    }
 
    if (!fs::exists(path)) return ERR_FILE_NOT_FOUND;
 
    std::ifstream f(path);
    std::stringstream buffer;
    buffer << f.rdbuf();
    std::string content = buffer.str();
    if (content.empty()) {
        return "File is empty.";
    }
 
    return content;
}
 
std::string CommandProcessor::handleCreate(const std::string& file) {
    std::string path = file;
    if (!path.empty() && path[0] == '~') {
        const char* home = std::getenv("HOME");
        if (home) path = std::string(home) + path.substr(1);
    }
    std::ofstream f(path);
 
    return f ? SUCCESS_FILE_CREATED : ERR_FILE_CREATE_FAILED;
}
 
std::string CommandProcessor::handleRemove(const std::string& file) {
    std::string path = file;
     if (!path.empty() && path[0] == '~') {
        const char* home = std::getenv("HOME");
        if (home) path = std::string(home) + path.substr(1);
    }
    return (remove(path.c_str()) == 0) ? SUCCESS_FILE_REMOVED : ERR_FILE_REMOVE_FAILED;
}
