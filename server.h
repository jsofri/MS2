//
// Created by yehonatan on 09/01/2020.
//

#ifndef SERVER_H
#define SERVER_H

#include "client_handler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int, ClientHandler) = 0;
        virtual void stop() = 0;
    private:
        virtual void run(int &, ClientHandler &) = 0;
    };
}


#endif //SERVER_H
