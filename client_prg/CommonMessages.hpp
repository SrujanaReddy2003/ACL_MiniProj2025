#ifndef COMMON_MESSAGES_HPP
#define COMMON_MESSAGES_HPP

// Success messages
#define SUCCESS_CONNECTED_TO_SERVER "Success: Connected to the server."
#define SUCCESS_FILE_SENT "Success: File was sent successfully."
#define SUCCESS_FILE_RECEIVED "Success: File received successfully."
#define SUCCESS_FILE_CREATED "Success: File created successfully."
#define SUCCESS_FILE_DELETED "Success: File removed successfully."
#define SUCCESS_COMMAND_EXECUTED "Success: Command executed successfully."
#define SUCCESS_CLIENT_CONNECTED "Connected to server successfully."

// Error messages
#define ERR_SOCKET_CREATION "Error: Could not create socket."
#define ERR_CONNECTION_FAILED "Error: Failed to connect to server."
#define ERR_INVALID_PROTOCOL "Error: Invalid protocol. Use -tcp or -udp."
#define ERR_INVALID_ARGS "Error: Invalid number of arguments. Usage: ./iftp_client -cl -tcp/-udp <IP> <PORT>"
#define ERR_UNSUPPORTED_MODE "Error: Only client mode (-cl) is supported."
#define ERR_SERVER_UNREACHABLE "Error: Ping failed. Server is not reachable."

#define ERR_FILE_NOT_FOUND "Error: File not found."
#define ERR_FILE_CREATE_FAILED "Error: Could not create file."
#define ERR_FILE_REMOVE_FAILED "Error: Could not remove file."
#define ERR_DIR_NOT_FOUND "Error: Directory not found."
#define ERR_PERMISSION_DENIED "Error: Permission denied."
#define ERR_UNKNOWN "Error: Unknown error occurred."
#define ERR_INVALID_COMMAND "Error: Invalid command."

#endif // COMMON_MESSAGES_HPP

