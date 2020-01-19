//
// Created by yehonatan on 19/01/2020.
//

#ifndef MATRIX_GENERATOR_H_
#define MATRIX_GENERATOR_H_

#include <iostream>
#include "cstring"
#define RANK 10
#define RAND 1000

using namespace std;
class MatrixGenerator {
 private:
  static void printAndClose(string, string);
 public:
  static void makeMatrices();
};

#endif //MATRIX_GENERATOR_H_
