//
// Created by yehonatan on 13/01/2020.
//

#include "string_wrapper.h"

unsigned long StringWrapper::toHash() {
    std::hash<string> hash_f;

    return hash_f(value_);
}

string StringWrapper::getValue() {
    return value_;
}