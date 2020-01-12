//
// Created by yehonatan on 09/01/2020.
//

#ifndef MY_TEST_CLIENT_HANDLER_H
#define MY_TEST_CLIENT_HANDLER_H

#include "client_handler.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sys/socket.h>

namespace server_side {
    class MyTestClientHandler : public ClientHandler {
    public:
        void handleClient(int &);
    private:
        int reverseString(char *);
    };
}


#endif //MY_TEST_CLIENT_HANDLER_H
