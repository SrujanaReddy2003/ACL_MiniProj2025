#include "ClientTCP.hpp"
#include "ClientUDP.hpp"
#include "CommonMessages.hpp"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << ERR_INVALID_ARGS << endl;
        return 1;
    }
 
    string mode = argv[1];
    string proto = argv[2];
    string ip = argv[3];
    int port = stoi(argv[4]);
 
    if (mode != "-cl") {
       cout << ERR_UNSUPPORTED_MODE << endl;
        return 1;
    }
 
 
    if (proto == "-tcp") {
        ClientTCP client(ip, port);
        if (!client.checkConnection()) {
         cout << ERR_SERVER_UNREACHABLE << endl;
            return 1;
        }
        cout << SUCCESS_CLIENT_CONNECTED << endl;
        client.run();
 
    } else if (proto == "-udp") {
        ClientUDP client(ip, port);
         if (!client.checkConnection()) {
          cerr << ERR_SERVER_UNREACHABLE << endl;
            return 1;
        }
 
        cout << SUCCESS_CLIENT_CONNECTED << endl;
        client.run();
    } else {
        cout << ERR_INVALID_PROTOCOL << endl;
        return 1;
    }
 
    return 0;
}
