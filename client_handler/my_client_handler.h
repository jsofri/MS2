//
// Created by yehonatan on 19/01/2020.
//

#ifndef CLIENT_HANDLER_MY_CLIENT_HANDLER_H_
#define CLIENT_HANDLER_MY_CLIENT_HANDLER_H_

#include "client_handler.h"
#include "string"
#include <unistd.h>
#include "../util/stringer.h"
#include "../objects/matrix.h"
#include "../builders/matrix_builder.h"
#include "../searchables/searchable.h"
#include "../searchables/matrix_searchable.h"

#define END "end\n"

class MyClientHandler : public ClientHandler {
 public:
  void handleClient(int &);
 private:
  bool endNotEntered();
  void setAndSolveMatrix();
  MatrixSearchable makeSearchable();
  list<string> lines_list_;
};

#endif //CLIENT_HANDLER_MY_CLIENT_HANDLER_H_
