//
// Created by yehonatan on 14/01/2020.
//


#include "matrix_builder.h"


void MatrixBuilder::addRow(string row) {
  vector<string> string_vector;

  string_vector = Stringer::doRegex(row, REGEX);
  setValuesInVector(string_vector);
}

void MatrixBuilder::setValuesInVector(vector<string> & string_vector) {
  vector<int> int_vector;

  for (auto num_string : string_vector) {

    try {
      int_vector.push_back(stoi(num_string));

    }catch (const std::invalid_argument& ia) {
      throw "unable to convert string to int";
    }
  }

  int_matrix_.addRow(int_vector);
}

void MatrixBuilder::buildNXNMatrix(list<string> input) {
    auto first_row = Stringer::doRegex(input.front(), REGEX);
    int n = first_row.size();
    list<string>::iterator iter = input.begin();

    //add first n rows to matrix
    while (n-- > 0) {
        addRow(*iter);
        iter++;
    }
}

Matrix<int> MatrixBuilder::getMatrix() {
  return int_matrix_;
}