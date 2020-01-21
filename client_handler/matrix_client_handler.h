//
// Created by rony on 19/01/2020.
//

#ifndef MATRIX_CLIENT_HANDLER_H
#define MATRIX_CLIENT_HANDLER_H

#include <list>
#include <unistd.h>
#include "client_handler.h"
#include "../util/stringer.h"


class MatrixClientHandler : public ClientHandler {
public:
    void handleClient(int &) override;
private:
    bool keep_running_ = true;
};


#endif //MATRIX_CLIENT_HANDLER_H
