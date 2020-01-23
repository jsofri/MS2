//
// Created by yehonatan on 19/01/2020.
//

#include "my_client_handler.h"

using namespace std;

void MyClientHandler::handleClient(int & client_socket) {
    list<string> lines_list;
    string str;

    do {
        char buffer[BUFFER_SIZE] = {0};
        int valread = read(client_socket , buffer, BUFFER_SIZE);

        list<string> tmp_list = Stringer::stringListFromCharArray(buffer);

        //add tmp_list to lines_list
        lines_list.insert(lines_list.end(), tmp_list.begin(), tmp_list.end());

    } while (endNotEntered(lines_list));

    str = setAndSolveMatrix(lines_list);

    //send solution to client
    send(client_socket , str.c_str() , strlen(str.c_str()) , 0 );

    close(client_socket);
}

bool MyClientHandler::endNotEntered(list<string> lines_list) {
  string last_line;
  bool endIn = false;

    if(lines_list.size() > 0) {
       last_line = lines_list.back();
    }

  if (last_line != "" && last_line.length() <= 5) {
    endIn = (last_line.length() == strspn(last_line.c_str(), END));
  }

  return !endIn;
}

string MyClientHandler::setAndSolveMatrix(list<string> lines_list) {
    try {
        auto searchable = makeSearchable(lines_list);
        string solution;
        MatrixAdapter matrix_adapter;

        if (file_cache_manager.exist(&searchable)) {
            solution = file_cache_manager.get(&searchable);
        } else {
            solution = matrix_adapter.solve(searchable);
            file_cache_manager.insert(&searchable, solution);
        }

        return solution;
    } catch (const char * e) {
        return e;
    }
}

MatrixSearchable MyClientHandler::makeSearchable(list<string> lines_list) {
  MatrixBuilder matrix_builder;
  Matrix<int> matrix;
  list<string>::iterator iter;

  if (!inputIsGood(lines_list)) {
      throw "Invalid input\n";
  }
  //make list to hold one line in each node
  lines_list = Stringer::listOfLines(lines_list);

  matrix_builder.buildNXNMatrix(lines_list);

  matrix = matrix_builder.getMatrix();

  iter = lines_list.end();
  --iter;//go to last string - "end\n"
  Point end = Stringer::pointFromString(*(--iter));
  Point start = Stringer::pointFromString(*(--iter));

  return MatrixSearchable(matrix, start, end);
}

//check that list of string represent a real searchable
bool MyClientHandler::inputIsGood(list<string> list) {
    string first_row = list.front();
    int commas, i, n = first_row.size();
    std::list<string>::iterator iter;
    bool ok = true;

    if (list.size() < 4) {
        ok = false;
    }

    for (commas = 0, i = 0; i < n; i++) {
        if (first_row[i] == ',') {
            commas++;
        }
    }

    if (list.size() > commas + 4) {
        ok = false;
    }

    iter = list.end();
    iter--;//now in end\n
    try {
        Point p1 = Stringer::pointFromString(*(--iter));//now in end point
        Point p2 = Stringer::pointFromString(*(--iter));//now in start point
        int x1, x2, y1, y2;
        x1 = p1.getX();
        x2 = p2.getX();
        y1 = p1.getY();
        y2 = p2.getY();

        if (((x1 < 0 || x1 > commas) || (x2 < 0 || x2 > commas))
            || ((y1 < 0 || y1 > commas) || (y2 < 0 || y2 > commas))){
            ok = false;
        }
    } catch (const char * e) {
        ok = false;
    }

    return ok;
}