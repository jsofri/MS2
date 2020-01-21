//
// Created by yehonatan on 19/01/2020.
//

#define MAX_LINE_LENGTH 2048

#include <builders/matrix_builder.h>
#include "matrix_generator.h"

Matrix<int> MatrixGenerator::randomMatrix(int rank) {
    int x, y, i, j;
    Matrix<int> matrix;

    for (i = 0; i < rank; i++) {
        vector<int> row;
        for (j = 0; j < rank; j++) {
            x = (rand() % (RAND + 1)); // 0 to RAND
            y = (rand() % 101) - 1; // 0 to 100

            if (!((i == rank -1 && j == rank - 1) || (i == 0 && j == 0)) && (x + y) % RAND_WALL == 0) {
                x = -1;
            }

            row.push_back(x);
        }
        matrix.addRow(row);
    }

    return matrix;
}

Matrix<int> MatrixGenerator::fromFile(string file_name) {
    FILE *fp;

    fp = fopen(file_name.c_str(), "r");

    if (fp == NULL) {
        perror("can't write matrix to file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    auto mb = new MatrixBuilder();

    // add each row to matrix
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        string str = Stringer::getAllCharsInCharArray(line);
        mb -> addRow(str);
    }

    // close file
    fclose(fp);

    auto matrix = mb -> getMatrix();
    return matrix;
}
