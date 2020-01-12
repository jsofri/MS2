//
// Created by yehonatan on 09/01/2020.
//

#ifndef MYSERIALSERVER_H
#define MYSERIALSERVER_H

#include "sys/socket.h"
#include "server.h"
#include "client_handler.h"
#include <thread>
#include "iostream"
#include <netinet/in.h>
#include <unistd.h>


namespace server_side {
    class MySerialServer : public Server {
    public:
        void open(int, ClientHandler*);
        void close();
    private:
        void run(int &, ClientHandler* &);
        bool keep_running_;
        std::thread server_thread_;
    };
}

#endif //MYSERIALSERVER_H
