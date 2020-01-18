//
// Created by rony on 13/01/2020.
//

#include "server/my_serial_server.h"
#include "client_handler/my_test_client_handler.h"
#include "objects/matrix.h"
#include "MatrixAdapter.h"
#include "iostream"
#include "string"
#include "matrix_searchable.h"
#include "searchers/matrix_dfs.h"
#include "searchers/matrix_bfs.h"
#include "searchers/matrix_best_fs.h"
#define PORT 5402
#define RANK 4

using namespace server_side;

void foo() {
  MatrixAdapter matrix_adapter;
  string str = "";
  int x, i, j;

  for (i = 0; i < RANK; i++) {
    for (j = 0; j < RANK; j++) {
      x = rand() % 100;         // v1 in the range 0 to 99
      str += to_string(x);
      str+=",";
    }
    matrix_adapter.addRow(str);
    cout << str << endl;
    str = "";
  }

  Matrix<int> matrix = matrix_adapter.getMatrix();

  MatrixSearchable matrix_searchable(&matrix);

  //MatrixBFS matrix_bfs;
  MatrixBestFS matrix_best_fs;

  str = matrix_best_fs.search(matrix_searchable);

  cout << str << endl;
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
    
    return 0;
}