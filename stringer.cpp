//
// Created by yehonatan on 12/01/2020.
//

#include "stringer.h"

using namespace std;


string Stringer::stringFromCharArray(char* array) {
    string result = "";
    int i = 0;

    while (array[i] != '\0') {
        result += array[i];
    }

    return result;
}
