//
// Created by yehonatan on 12/01/2020.
//

#ifndef STRINGER_H
#define STRINGER_H

#include <list>
#include "cstring"
#include "string"
#include "vector"
#include "regex"
#include "../objects/point.h"
#include "../builders/matrix_builder.h"


using namespace std;


class Stringer {
public:
    static string lineFromCharArray(char*);
    static list<string> stringListFromCharArray(char *);
    static vector<string> doRegex(string, string);
    static list<string> listOfLines(list<string>);
    static Point pointFromString(string);
};


#endif //STRINGER_H