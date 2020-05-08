#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>

using namespace std;

class peer {
    public:
    int socket;
    int port;
    char * address;
    bool choked;
    bool interested;
    int peer_id;

    sock(int id) {
        socket = -1;
        port = 0;
        address = "";
        choked = true;
        interested = false;
        peer_id = id;
    }
    // Initializes the peer information
    bool setup(char *address, int p) {
        if (sock == -1) {

            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                cout << "Socket failed" << edl;
                return false;
            }
        }   
        sockaddr_in h;
        h.sin_family = AF_INET;
        h.sin_port = htons(port);
        inet_pton(AF_INET, address.c_str(), &h.sin_addr);

        port = p;
        this.address = address;
        int conn = connect(sock, (sockaddr*)&h, sizeof(h));
        if (conn == -1) {
            return false;
        }
        return true;
    }
    // Send data to the socket connection
    bool Send(string data) {
        if (sock != -1) {

            if (send(sock, data.c_str(), strlen(data), 0 ) < 0) {
                cout << "Sending failed : " << data << endl;
                return false;
            }
        }
        else {
         return false;
        }
        return true;
    }
    // Reads set amount of bytes from recv
    std::string receive(int size) {
        char buff[size];
        memset(&buffer[0], 0, sizeof(buff));

        string reply;
        if (recv(sock, buff, size, 0) < 0) {
            cout << "receive failed" << endl;
            return nullptr;
        }
        buffer[size-1] = '\0';
        reply = buffer;
        return reply;
    }
    // Same as receive but takes it byte-by-byte
    std::string read() {
        char buffer[1] = 0;
        string reply;
        while (buffer[0] != '\n' && buffer[0] != '\0') {
            if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
                cout << "receive failed" << endl;
                return nullptr;
            }
            reply += buffer[0];
        }
        return reply;
    }

};


