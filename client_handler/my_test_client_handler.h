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
#include "../solvers/string_reverser.h"
#include "../util/stringer.h"
#include "../cache_manager/file_cache_manager.h"
#include "../global_vars.h"


class MyTestClientHandler : public ClientHandler {
public:
    void handleClient(int &);
private:
    FileCacheManager<StringWrapper*, string> file_cache_manager_;
    StringReverser solver_;
};


#endif //MY_TEST_CLIENT_HANDLER_H
