//
// Created by rony on 19/01/2020.
//

#include "../objects/matrix.h"
#include "matrix_int_to_file.h"

void MatrixIntToFile::write(Matrix<int> matrix, string file_name) {
    FILE *fp;

    fp = fopen(file_name.c_str(), "w");

    if (fp == NULL) {
        perror("can't write matrix to file");
        exit(1);
    }

    string output;

    auto rowsNum = matrix.getSize().first;
    auto colsNum = matrix.getSize().second;

    for (int i = 0; i < rowsNum; i++) {
        output = "";
        for (int j = 0; j < colsNum; j++) {
            output += to_string(matrix[i][j]);
            if (j < colsNum - 1) {
                output += ", ";
            }
        }
        output += "\n";
        fputs(output.c_str(), fp);
    }

    fclose(fp);
}