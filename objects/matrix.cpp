//
// Created by yehonatan on 14/01/2020.
//


#include "matrix.h"

using namespace std;

Matrix::Matrix(string str) {

  addRow(str);


  /*
  matrix_.push_back(ss);
  matrix_[0].push_back(1);
  matrix_[0].push_back(2);
  matrix_[1].push_back(3);
  matrix_[1].push_back(4);
   */
}


void Matrix::setCell(Point & p, int & value) {
    if (p.getY() >= columns_ || p.getX() >= columns_) {
      throw "can't put value in cell";
    }

    matrix_[p.getX()][p.getY()] = value;
}
void Matrix::addRow(string row) {
  vector<string> string_vector = Stringer::doRegex(row, REGEX);
  setValuesInVector(string_vector);
}

void Matrix::setValuesInVector(vector<string> & string_vector) {
  vector<int> int_vector;
  unsigned int length = 0;

  for (auto num_string : string_vector) {
    length++;

    try {
        int_vector.push_back(stoi(num_string));

    }catch (const std::invalid_argument& ia) {
        throw "unable to convert string to int";
    }
  }

  if (!columns_) {
    columns_ = length;
  } else if (columns_ != length) {
    throw "error in number of columns";
  }

  matrix_.push_back(int_vector);
  rows_++;
}

vector<int> & Matrix::operator[](int i) {
  return matrix_[i];
}