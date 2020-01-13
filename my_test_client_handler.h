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
#include "string_reverser.h"
#include "stringer.h"
#include "file_cache_manager.h"


class MyTestClientHandler : public ClientHandler {
public:
    void handleClient(int &);
private:
    FileCacheManager<StringWrapper, string> file_cache_manager_;
    StringReverser solver_;
};


#endif //MY_TEST_CLIENT_HANDLER_H
