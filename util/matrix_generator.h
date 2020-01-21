//
// Created by yehonatan on 19/01/2020.
//

#ifndef MATRIX_GENERATOR_H_
#define MATRIX_GENERATOR_H_

#include <iostream>
#include "cstring"
#include "../objects/matrix.h"

#define RAND 3
#define RAND_WALL 20

using namespace std;
class MatrixGenerator {
public:
    static Matrix<int> randomMatrix(int);
    static Matrix<int> fromFile(string);
};

#endif //MATRIX_GENERATOR_H_
