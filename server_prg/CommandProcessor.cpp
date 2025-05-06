#include "CommandProcessor.hpp"
#include "CommonMessages.hpp"
#include "CommonHeader.hpp"

namespace fs = std::filesystem;
 
std::string CommandProcessor::process(const std::string& message) {
    if (message == "ping") return SUCCESS_CONNECTED;
 
    if (message.find("-ls") == 0) {
        std::string dir = message.substr(3);
        return handleList(dir);
    }
 
    if (message.find("-re") == 0) {
        std::string file = message.substr(4);
        return handleRead(file);
    }
 
    if (message.find("-cr") == 0) {
        std::string file = message.substr(4);
        return handleCreate(file);
    }
    if (message.find("-cp") == 0) {
    std::istringstream iss(message.substr(4)); // Skip "-cp "
    std::string src, dest;
    iss >> src >> dest;
 
    if (src.empty() || dest.empty()) {
        return ERR_INVALID_COMMAND;
    }
 
    return handleCopy(src, dest);
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


    if (dir.empty()) dir = fs::current_path().string();

    // Use opendir for permission/error checking
    DIR* d = opendir(dir.c_str());
    if (!d) {
        switch (errno) {
            case EACCES:
                return ERR_PERMISSION_DENIED;
            case ENOENT:
                return ERR_DIR_NOT_FOUND;
            default:
                return ERR_UNKNOWN;
        }
    }
    closedir(d);

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

std::string CommandProcessor::handleCopy(const std::string& src, const std::string& dest) {
    std::ifstream in(src, std::ios::binary);
    if (!in) {
        return ERR_FILE_NOT_FOUND;
    }

    std::ofstream out(dest, std::ios::binary);
    if (!out) {
        return ERR_FILE_CREATE_FAILED;
    }

    out << in.rdbuf();
    return SUCCESS_FILE_COPIED;
}
 
std::string CommandProcessor::handleCreate(const std::string& file) {
    std::string path = file;
    std::ofstream f(path);
    if(!fs::exists(path))return ERR_PATH_NOT_FOUND;
    return f ? SUCCESS_FILE_CREATED : ERR_FILE_CREATE_FAILED;
}
 
std::string CommandProcessor::handleRemove(const std::string& file) {
    std::string path = file;
    return (remove(path.c_str()) == 0) ? SUCCESS_FILE_REMOVED : ERR_FILE_REMOVE_FAILED;
}
