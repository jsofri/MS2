//
// Created by rony on 13/01/2020.
//

#include "server/my_serial_server.h"
#include "client_handler/my_test_client_handler.h"
#include "objects/matrix.h"
#include "iostream"
#include "string"
#define PORT 5402

using namespace server_side;

void foo() {
  Matrix a("1,2,3,4\n");
  Point p(1,2);
  int x = 3;
  try {
    a.addRow("5,6,7,-8");
    a.addRow("-9, -10, 11, 12");
  } catch (const char * c) {
    cerr << c << endl;
  }
  3+5/2+4;
  a.setCell(p, x);

  a[2][1] = 1;
}

int main() {
  foo();

  /*MySerialServer sersev;
    try {
        sersev.open(PORT, new MyTestClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }*/
}