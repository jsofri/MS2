//
// Created by yehonatan on 14/01/2020.
//


#include "matrix_builder.h"


void MatrixBuilder::addRow(string row) {
  vector<string> string_vector;

  string_vector = Stringer::doRegex(row, REGEX);
  setValuesInVector(string_vector);
}

void MatrixBuilder::setValuesInVector(vector<string> & string_vector) {
  vector<int> int_vector;

  for (auto num_string : string_vector) {

    try {
      int_vector.push_back(stoi(num_string));

    }catch (const std::invalid_argument& ia) {
      throw "unable to convert string to int";
    }
  }

  int_matrix_.addRow(int_vector);
}

void MatrixBuilder::buildNXNMatrix(list<string> input) {
  auto first_row = Stringer::doRegex(input.front(), REGEX);
  int n = first_row.size();
  list<string>::iterator iter = input.begin();

  //add first n rows to matrix
  while (n-- > 0) {
    addRow(*iter);
    iter++;
  }
}

Matrix<int> MatrixBuilder::getMatrix() {
  return int_matrix_;
}

Matrix<int> MatrixBuilder::fromFile(string file_name) {
    FILE *fp;

    fp = fopen(file_name.c_str(), "r");

    if (fp == NULL) {
        perror("can't read matrix from file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    auto mb = new MatrixBuilder();

    // add each row to matrix
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        string str = Stringer::lineFromCharArray(line);
        mb -> addRow(str);
    }

    // close file
    fclose(fp);

    auto matrix = mb -> getMatrix();
    return matrix;
}

Matrix<int> MatrixBuilder::randomMatrix(int rank) {
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

void MatrixBuilder::writeToFile(Matrix<int> matrix, string file_name) {
    FILE *fp;

    fp = fopen(file_name.c_str(), "w");

    if (fp == nullptr) {
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