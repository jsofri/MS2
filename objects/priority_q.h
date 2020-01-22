//
// Created by rony on 18/01/2020.
//

#ifndef PRIORITY_Q_H
#define PRIORITY_Q_H

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
class PriorityQ: public deque<T> {
public:
    void sort() {
        std::sort(this -> begin(), this -> end(), [this] (T p1, T p2) { return (p2 -> weightH > p1 -> weightH); });
    }


};


#endif //PRIORITY_Q_H
