//
// Created by yehonatan on 12/01/2020.
//

#ifndef STRINGREVERSER_H
#define STRINGREVERSER_H


#include <string>
#include "solver.h"
#include "objects/string_wrapper.h"


using namespace std;

class StringReverser : public Solver<StringWrapper, string> {
public:
    string solve(StringWrapper &);
};


#endif //STRINGREVERSER_H
