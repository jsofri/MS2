//
// Created by yehonatan on 12/01/2020.
//

#ifndef HASHER_H
#define HASHER_H


#include "string"
#include <unordered_map>


using namespace std;

template <typename T>
class Hasher {
public:
    static size_t getHash(T);
    static size_t getHash(string);
};


#endif //HASHER_H
