//
// Created by rony on 13/01/2020.
//

#include "server/my_serial_server.h"
#include "client_handler/my_test_client_handler.h"
#include "objects/matrix.h"
#include "builders/matrix_builder.h"
#include "iostream"
#include "string"
#include "searchables/matrix_searchable.h"
#include "searchers/matrix_dfs.h"
#include "searchers/matrix_bfs.h"
#include "searchers/matrix_astar.h"
#include "searchers/matrix_best_fs.h"
#define PORT 5402
#define RANK 10
#define RAND 3

using namespace server_side;

void foo() {
    MatrixBuilder matrix_builder;
    string str = "";
    int x, i, j;

    for (i = 0; i < RANK; i++) {
        for (j = 0; j < RANK; j++) {
            x = rand() % RAND;         // v1 in the range 0 to RAND
            str += to_string(x);
            str+=",";
        }
        matrix_builder.addRow(str);
        cout << str << endl;
        str = "";
    }

    Matrix<int> matrix = matrix_adapter.getMatrix();

    MatrixSearchable matrix_searchable(&matrix);

  
    //MatrixBFS matrix;
    //MatrixAStar matrix;
    MatrixBestFS matrix;
  
    str = matrix.search(matrix_searchable);

    cout << str << endl;
}

int main() {
    foo();
    return 0;
}

/**
 * Testing part 2
 */
int mainPart2() {
    MySerialServer sersev;
    try {
        sersev.open(PORT, new MyTestClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }

    return 0;
}