//
// Created by yehonatan on 09/01/2020.
//


#include "my_serial_server.h"

using namespace server_side;

void MySerialServer::open(int port, ClientHandler *client_handler) {
    keep_running_ = true;
    server_thread_ = std::thread(&MySerialServer::run, this, port, client_handler);
}


void MySerialServer::close() {
    keep_running_ = false;
    server_thread_.join();
}

void MySerialServer::run(int & port, ClientHandler* & client_handler){

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    }
    //Server is now listening

    int client_socket;
    while (keep_running_) {
        client_socket = accept(socketfd, (struct sockaddr *)&address,
                                  (socklen_t*)&address);
        if (client_socket != -1) {
            client_handler -> handleClient(client_socket);
        }
    }
    // accepting a client


    if (client_socket == -1) {
        throw "Error accepting client";
    }

    ::close(socketfd); //closing the listening socket
}

