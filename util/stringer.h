//
// Created by yehonatan on 12/01/2020.
//

#ifndef STRINGER_H
#define STRINGER_H


#include "cstring"
#include "string"
#include "vector"
#include "regex"


using namespace std;


class Stringer {
public:
    static string firstLineInCharArray(char*);
    static string getAllCharsInCharArray(char*);
    static vector<string> doRegex(string, string);
};


#endif //STRINGER_H
