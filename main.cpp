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

bool endNotEntered(list<string> lines_list_) {
  string last_line = lines_list_.back();
  bool endIn = false;

  if (last_line.size() < 5) {
    endIn = (last_line.size() == strspn(last_line.c_str(), "end\n"));
  }

  return endIn;
}

void doo() {
  list <string> lines_list_;
  char buffer[BUFFER_SIZE];
  string str;

  do {
    cin >> buffer;

    list<string> tmp_list = Stringer::stringListFromCharArray(buffer);

    //add tmp_list to lines_list_
    lines_list_.insert(lines_list_.end(), tmp_list.begin(), tmp_list.end());

  } while (endNotEntered(lines_list_));
}
/*
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
*/

void hoo(){
  MatrixBuilder matrix_builder;
  Matrix<int> matrix;
  list<string> list;

  list.push_back("5,6,-1,2,1");
  list.push_back("0\n3,2,4,3,6\n1");
  list.push_back(",-1,9,3,3\n4");
  list.push_back(",5,6,7,8\n9,10,-1,2,3\n0");
  list.push_back(",0\n4,4\nend\n");

  matrix_builder.buildNXNMatrix(Stringer::listOfLines(list));

  matrix = matrix_builder.getMatrix();

  cout << matrix.getSize().second << endl;
}

int main() {
    hoo();
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