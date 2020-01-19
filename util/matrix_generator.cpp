//
// Created by yehonatan on 19/01/2020.
//

#include "matrix_generator.h"

  //method get a string and file name and appends the string in specified file
void MatrixGenerator::printAndClose(string str, string file_name) {

  FILE *fp;

  fp = fopen(file_name.c_str(), "a");

  if (fp != NULL) {
    fputs(str.c_str(), fp);
  }

  fclose(fp);
}

void MatrixGenerator::makeMatrices() {
  string str, file_name;
  int s, x, i, j, rank;

  for (s = RANK, rank = RANK; rank <= 50; rank++, s++) {
    file_name = "matrix" + to_string(s);

    for (i = 0; i < s; i++) {
      str = "";
      for (j = 0; j < s; j++) {
        x = (rand() % RAND) - 1;
        str += to_string(x);

        if (j != s - 1) {
          str += ",";
        }
      }
      str += '\n';
      printAndClose(str, file_name);
    }

    printAndClose("0,0\n", file_name);
    str = to_string(s - 1) + ", " + to_string(s - 1) + '\n';
    printAndClose(str, file_name);
  }
}
