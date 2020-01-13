//
// Created by yehonatan on 12/01/2020.
//all rights reserved for Yehonatan Sofri & Rony Utevsky

#include "hasher.h"


using namespace std;


template <typename T>
size_t Hasher<T>::getHash(T object) {
    unsigned int size, i = 0;
    char* onHeap;
    string str = "";
    std::hash<string> hash_f;

    size = sizeof(object);
    onHeap = (char *) malloc(size * sizeof(char));

    while (i < size) {
        str += onHeap[i++];
    }

    delete (onHeap);

    return hash_f(str);
}

size_t getHash(string str) {
    std::hash<string> hash_f;
    return hash_f(str);
}