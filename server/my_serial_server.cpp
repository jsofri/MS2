//
// Created by yehonatan on 09/01/2020.
//


#include "my_serial_server.h"


using namespace server_side;
using namespace std;

void MySerialServer::open(int port, ClientHandler * client_handler) {
    keep_running_ = true;
    //server_thread_ = thread(&MySerialServer::run, this, ref(port), ref(client_handler));
    run(port, client_handler);
}


void MySerialServer::close() {
    keep_running_ = false;
    //server_thread_.join();
}

void MySerialServer::run(int & port, ClientHandler* & client_handler){

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }

    //bind socket to IP address
    // we first need to creatargumentse the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port
    if (listen(socketfd, SOMAXCONN) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    }

    // set the time out
    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Server is now accepting clients
    acceptClients(socketfd, address, client_handler);

    // close listening server socket
    ::close(socketfd);
    close();
}

void MySerialServer::acceptClients(int socketfd, sockaddr_in& address, ClientHandler* client_handler) {
    int client_socket;

    // set the time out
    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while (keep_running_) {
        // accept client
        auto s = (struct sockaddr *) &address;
        auto m = (socklen_t *) &address;
        client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);

        if (client_socket != -1) {
            client_handler -> handleClient(client_socket);
        } else {
            break;
        }

        cout << "Client ended the connection" << endl;

    }
}
