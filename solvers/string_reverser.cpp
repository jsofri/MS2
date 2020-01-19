//
// Created by yehonatan on 12/01/2020.
//


#include "string_reverser.h"


string StringReverser::solve(StringWrapper & string_wrapper) {
    char tmp;
    string str = string_wrapper.getValue();
    int length = str.length();

    for (int i = 0; i < length / 2; i++) {
        tmp = str[i];
        str[i] = str[length - 1 - i];
        str[length -1 - i] = tmp;
    }

    return str;
}