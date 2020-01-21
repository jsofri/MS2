//
// Created by rony on 19/01/2020.
//

#include "print_to_file.h"

//method get a string and file name and appends the string in specified file
void PrintToFile::write(string& value, string file_name) {
    FILE *fp;

    file_name = file_name;
    fp = fopen(file_name.c_str(), "w");

    if (fp != nullptr) {
        fputs(value.c_str(), fp);
    }

    fclose(fp);
}