//
// Created by yehonatan on 14/01/2020.
//

#ifndef MATRIXADAPTER_H_
#define MATRIXADAPTER_H_


#include "objects/matrix.h"
#include "string"
#include "util/stringer.h"


#define REGEX "[-]{0,1}[\\d]+[.]{0,1}[\\d]{0,}"


class MatrixAdapter {
 public:
  MatrixAdapter();
  void addRow(string);
  Matrix<int> getMatrix();
 private:
  void setValuesInVector(vector<string> &);
  Matrix<int> int_matrix_;
};

#endif //MS2__MATRIXADAPTER_H_
