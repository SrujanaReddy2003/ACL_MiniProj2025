#ifndef COMMON_MESSAGES_HPP
#define COMMON_MESSAGES_HPP
 
#include <string>
 
const std::string SUCCESS_CONNECTED_TO_SERVER = "Success: Connected to the server.";
const std::string SUCCESS_FILE_SENT = "Success: File was sent successfully.";
const std::string SUCCESS_FILE_RECEIVED = "Success: File received successfully.";
const std::string SUCCESS_FILE_CREATED = "Success: File created successfully.";
const std::string SUCCESS_FILE_DELETED = "Success: File removed successfully.";
const std::string SUCCESS_COMMAND_EXECUTED = "Success: Command executed successfully.";
 
const std::string ERR_SOCKET_CREATION = "Error: Could not create socket.";
const std::string ERR_CONNECTION_FAILED = "Error: Failed to connect to server.";
const std::string ERR_INVALID_PROTOCOL = "Error: Invalid protocol specified.";
 
#endif // COMMON_MESSAGES_HPP
