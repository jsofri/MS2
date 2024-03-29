//
// Created by yehonatan on 19/01/2020.
//

#ifndef CLIENT_HANDLER_MY_CLIENT_HANDLER_H_
#define CLIENT_HANDLER_MY_CLIENT_HANDLER_H_

#include "client_handler.h"
#include "string"
#include <unistd.h>
#include <sys/socket.h>
#include "../solvers/matrix_adapter.h"
#include "../util/stringer.h"
#include "../objects/matrix.h"
#include "../builders/matrix_builder.h"
#include "../searchables/searchable.h"
#include "../searchables/matrix_searchable.h"
#include "../global_vars.h"

#define END "end\r\n"

class MyClientHandler : public ClientHandler {
 public:
  void handleClient(int &);
 private:
  bool endNotEntered(list<string>);
  bool inputIsGood(list<string>);
  string setAndSolveMatrix(list<string>);
  MatrixSearchable makeSearchable(list<string>);
};

#endif //CLIENT_HANDLER_MY_CLIENT_HANDLER_H_
