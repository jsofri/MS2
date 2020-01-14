//
// Created by yehonatan on 14/01/2020.
//

#ifndef OBJECTS_MATRIX_H_
#define OBJECTS_MATRIX_H_


#include "vector"
#include <iostream>
#include "point.h"

using namespace std;


template <typename T>
class Matrix {
 private:
  vector<vector<T>> matrix_;
  unsigned int rows_ = 0;
  unsigned int columns_ = 0;
 public:
  Matrix() = default;

  Matrix(vector<T> vector) {
    matrix_.push_back(vector);
    columns_ = vector.size();
  }

  void setCell(Point & p , T & value) {
    if (p.getY() >= columns_ || p.getX() >= columns_) {
      throw "can't put value in cell";
    }

    matrix_[p.getX()][p.getY()] = value;
  }

  T getCell(unsigned int row, unsigned int column) {
    return matrix_[row][column];
  }

  void addRow(vector<T> vector) {
    if (rows_ && (vector.size() != columns_)) {
      throw "cannot add vector to matrix - wrong number of columns";
    }

    matrix_.push_back(vector);
    rows_++;
  }

  vector<T> & operator[](unsigned int i) {
    return matrix_[i];
  }
};

#endif //OBJECTS_MATRIX_H_
