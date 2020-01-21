//
// Created by yehonatan on 14/01/2020.
//

#ifndef MATRIX_BUILDER_H_
#define MATRIX_BUILDER_H_

#include "../objects/matrix.h"
#include "string"
#include "../util/stringer.h"

#define RAND 3
#define RAND_WALL 20
#define MAX_LINE_LENGTH 2048
#define REGEX "[-]{0,1}[\\d]+[.]{0,1}[\\d]{0,}"

//Matrix Adapter can make matrix object from string
//each time you enter a string that represents a row
//string contains int seperated by commas
//e.g. "1, -2, 3, 4, 5"
//when you finished adding all rows, call getMatrix()

class MatrixBuilder {
 public:
  void addRow(string);
  void buildNXNMatrix(list<string>);
  Matrix<int> getMatrix();
  static Matrix<int> fromFile(string);
  static Matrix<int> randomMatrix(int);
  static void writeToFile(Matrix<int>, string);
private:
  void setValuesInVector(vector<string> &);
  Matrix<int> int_matrix_;
};

#endif //MATRIX_BUILDER_H_
