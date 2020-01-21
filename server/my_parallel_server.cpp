//
// Created by yehonatan on 21/01/2020.
//

#include "my_parallel_server.h"


using namespace server_side;
using namespace std;

void MyParallelServer::open(int port, ClientHandler * client_handler) {
    keep_running_ = true;
    //server_thread_ = thread(&MySerialServer::run, this, ref(port), ref(client_handler));
    run(port, client_handler);
}


void MyParallelServer::close() {
    keep_running_ = false;
    //server_thread_.join();
}

void MyParallelServer::run(int & port, ClientHandler* & client_handler){

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
    if (listen(socketfd, MAX_CLIENTS) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    }

    // set the time out
    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Server is now accepting clients
    acceptClients(socketfd, address, client_handler);

    for(auto iter = thread_list_.begin(); iter != thread_list_.end(); iter++) {
        (*iter).join();
    }

    // close listening server socket
    ::close(socketfd);
    close();
}

void MyParallelServer::acceptClients(int socketfd, sockaddr_in& address, ClientHandler* client_handler) {
    int client_socket;

    while (keep_running_) {
        // accept client
        auto s = (struct sockaddr *) &address;
        auto m = (socklen_t *) &address;
        client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);

        if (client_socket != -1) {
            //make new thread and add it to list and run it
            std::thread new_thread(&MyParallelServer::runOneClient, this, client_handler, client_socket);
            thread_list_.push_back(new_thread);
        } else {
            perror("Accept error");
        }

        cout << "Client ended the connection" << endl;
    }
}

void MyParallelServer::runOneClient(ClientHandler* client_handler, int client_socket) {
    client_handler -> handleClient(client_socket);
}
