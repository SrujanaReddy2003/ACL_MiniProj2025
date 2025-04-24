#include "ServerTCP.hpp"
#include "ServerUDP.hpp"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
  if (argc != 5) {
        cerr << "Usage: ./iftp_server -sr -tcp/-udp <IP> <PORT>\n";
        return 1;
    }
 
    string mode = argv[1];
    string proto = argv[2];
    string ip = argv[3];
    int port = stoi(argv[4]);
 
    if (mode != "-sr") {
     cerr << "Only Server mode (-sr) is supported in this main file.\n";
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
            cerr << "Invalid protocol. Use -tcp or -udp.\n" << endl;
            return 1;
        }
    }
 
    return 0;
}
