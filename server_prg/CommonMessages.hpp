#ifndef COMMON_MESSAGES_HPP
#define COMMON_MESSAGES_HPP

// Error Messages
#define ERR_SOCKET_CREATION     "Error creating socket."
#define ERR_BIND_FAILED         "Error binding socket."
#define ERR_INVALID_COMMAND     "Invalid command."
#define ERR_FILE_NOT_FOUND      "File not found."
#define ERR_DIR_NOT_FOUND       "Directory not found."
#define ERR_FILE_CREATE_FAILED  "Failed to create file."
#define ERR_FILE_REMOVE_FAILED  "Failed to remove file."
#define ERR_PERMISSION_DENIED "Error: Permission denied"
#define ERR_UNKNOWN "Error: Unknown error occurred"
#define ERR_FILE_ALREADY_EXISTS "File already exists"
// Success Messages
#define SUCCESS_CONNECTED       "Connected to server."
#define SUCCESS_FILE_CREATED    "File created successfully."
#define SUCCESS_FILE_REMOVED    "File removed successfully."
#define SUCCESS_FILE_COPIED     "File copied successfully."

//Usage
#define ERR_INVALID_ARGS "Usage: ./iftp_server -sr -tcp/-udp <IP> <PORT>\n"
#define ERR_UNSUPPORTED_MODE "Only Server mode (-sr) is supported in this main file.\n"
#define ERR_INVALID_PORT  "Invalid protocol. Use -tcp or -udp.\n"

#endif // COMMON_MESSAGES_HPP

