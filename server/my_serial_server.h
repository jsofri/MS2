//
// Created by yehonatan on 09/01/2020.
//

#ifndef MYSERIALSERVER_H
#define MYSERIALSERVER_H

#include "iostream"
#include "sys/socket.h"
#include "server.h"
#include "../client_handler/client_handler.h"
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "chrono"


namespace server_side {
    class MySerialServer : public Server {
    public:
        void open(int, ClientHandler*);
        void close();
    private:
        void run(int &, ClientHandler* &);
        void acceptClients(int, sockaddr_in&, ClientHandler*);
        bool keep_running_;
        std::thread server_thread_;
    };
}

#endif //MYSERIALSERVER_H
