#include "ClientTCP.hpp"
#include "ClientUDP.hpp"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: ./iftp_client -cl -tcp/-udp <IP> <PORT>\n";
        return 1;
    }
 
    string mode = argv[1];
    string proto = argv[2];
    string ip = argv[3];
    int port = stoi(argv[4]);
 
    if (mode != "-cl") {
       cerr << "Only client mode (-cl) is supported in this main file.\n";
        return 1;
    }
 
 
    if (proto == "-tcp") {
        ClientTCP client(ip, port);
        if (!client.checkConnection()) {
         cerr << "Error: Ping failed. Server is not reachable"<< endl;
            return 1;
        }
        cout << "Connected to server successfully." << endl;
        client.run();
 
    } else if (proto == "-udp") {
        ClientUDP client(ip, port);
         if (!client.checkConnection()) {
          cerr << "Error: Ping failed. Server is not reachable" << endl;
            return 1;
        }
 
        cout << "Connected to server successfully." << endl;
        client.run();
    } else {
        cerr << "Invalid protocol. Use -tcp or -udp.\n";
        return 1;
    }
 
    return 0;
}
