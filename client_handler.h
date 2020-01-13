//
// Created by yehonatan on 09/01/2020.
//

#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#define BUFFER_SIZE 1024

#include <iosfwd>

class ClientHandler {
public:
    virtual void handleClient(int &) = 0;
};


#endif //CLIENTHANDLER_H
