//
// Created by yehonatan on 13/01/2020.
//

#ifndef STRING_H
#define STRING_H

#include <string>

using namespace std;


class StringWrapper {
public:
    explicit StringWrapper(string s) : value_(s) {}
    unsigned long toString();
    string getValue();
private:
    string value_;
};


#endif //STRING_H
