//
// Created by yehonatan on 19/01/2020.
//


#include "my_client_handler.h"

using namespace std;

void MyClientHandler::handleClient(int & client_socket) {
  char buffer[BUFFER_SIZE];
  string str;

  do {
    int valread = read(client_socket , buffer, BUFFER_SIZE);

    list<string> tmp_list = Stringer::stringListFromCharArray(buffer);

    //add tmp_list to lines_list_
    lines_list_.insert(lines_list_.end(), tmp_list.begin(), tmp_list.end());

  } while (endNotEntered());

  return setAndSolveMatrix();
}

bool MyClientHandler::endNotEntered() {
  string last_line = lines_list_.back();
  bool endIn = false;

  if (last_line.size() < 5) {
    endIn = (last_line.size() == strspn(last_line.c_str(), END));
  }

  return endIn;
}

void MyClientHandler::setAndSolveMatrix() {
  Searchable<Point> * searchable = makeSearchable();

  if (file_cache_manager.exist(searchable)) {
    return file_cache_manager.get(matrix);
  } else {
    solution = objectAdapter.solve(searchable);
    file_cache_manager.insert(searchable, solution);
  }
  //solve using cachemanager
  //get solution
  //enter it to cache
  //return solution
}

Searchable<Point>* MyClientHandler::makeSearchable() {
  MatrixBuilder matrix_builder;
  Matrix<int> matrix;

  //make list to hold one line in each node
  lines_list_ = Stringer::listOfLines(lines_list_);

  matrix_builder.buildNXNMatrix(lines_list_);

  matrix = matrix_builder.getMatrix();


}

MyClientHandler::~MyClientHandler() {
  delete(searchable_);
}
