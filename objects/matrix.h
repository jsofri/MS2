//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_OBJECTS_MATRIX_H_
#define MS2_OBJECTS_MATRIX_H_


#include "vector"
#include "string"
#include <iostream>
#include "point.h"
#include "../util/stringer.h"


#define REGEX "[-]{0,1}[\\d]+[.]{0,1}[\\d]{0,}"


using namespace std;


class Matrix {
 public:
  Matrix(string);
  void setCell(Point &, int &);
  void addRow(string);
  vector<int> & operator[](int i);
 private:
  void setValuesInVector(vector<string> &);
  vector<vector<int>> matrix_;
  unsigned int rows_ = 0;
  unsigned int columns_ = 0;
};

#endif //MS2_OBJECTS_MATRIX_H_
