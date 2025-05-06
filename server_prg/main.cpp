#include "ServerTCP.hpp"
#include "ServerUDP.hpp"
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
 
    if (mode != "-sr") {
     cout << ERR_UNSUPPORTED_MODE << endl;
     return 1;
    }
 
    if (mode == "-sr") {
        if (proto == "-tcp") {
            ServerTCP server(ip, port);
            server.start(ip,port);
        } else if (proto == "-udp") {
            ServerUDP server(ip,port);
            server.start(ip,port);
        } else {
            cout << ERR_INVALID_PORT << endl;
            return 1;
        }
    }
 
    return 0;
}
