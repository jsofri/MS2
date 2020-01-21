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

  void setCell(Point & p , T value) {
    if (p.getY() >= columns_ || p.getX() >= columns_) {
      throw "can't put value in cell";
    }

    matrix_[p.getX()][p.getY()] = value;
  }

  void setCell(Point & p , T & value) {
    if (p.getY() >= columns_ || p.getX() >= columns_) {
      throw "can't put value in cell";
    }

    matrix_[p.getX()][p.getY()] = value;
  }

  T& getCell(unsigned int row, unsigned int column) {
    return matrix_[row][column];
  }

  T& getCell(Point point) {
      T& res = matrix_[point.getX()][point.getY()];
      return res;
  }

  void addRow(vector<T> vector) {
    if (!columns_) {
      columns_ = vector.size();
    } else if (rows_ && (vector.size() != columns_)) {
      throw "cannot add vector to matrix - wrong number of columns";
    }

    matrix_.push_back(vector);
    rows_++;
  }

  pair<unsigned int, unsigned int> getSize() {
    auto sizePair = std::pair<unsigned int, unsigned int>(rows_, columns_);

    return sizePair;
  }

  vector<T> & operator[](unsigned int i) {
    return matrix_[i];
  }

  vector<vector<T>>& getMatrix() {
      return matrix_;
  }
 
   string toString() {
    hash<Matrix> hash_matrix;

    return to_string(hash_matrix(this));
  }
};

#endif //OBJECTS_MATRIX_H_
