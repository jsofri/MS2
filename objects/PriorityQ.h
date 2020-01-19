//
// Created by rony on 18/01/2020.
//

#ifndef MS2_PRIORITYQ_H
#define MS2_PRIORITYQ_H

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T, typename U>
class PriorityQ: public deque<pair<T, U>> {
    deque<pair<T,U>> queue_;
    void sort() {
        std::sort(queue_.begin(), queue_.end(), [this] (pair<T, U> p1, pair<T, U> p2) { return (p2.first > p1.first); });
    }

public:
    void push(std::pair<T,U> pair) {
        queue_.push_back(pair);
        sort();
    }
    bool empty() {
        return queue_.empty();
    }

    typename deque<pair<T, U>>::iterator begin() {
        return queue_.begin();
    }

    pair<T, U> front() {
        return queue_.front();
    }

    void erase(typename deque<pair<T, U>>::iterator it) {
        queue_.erase(it);
    }


};


#endif //MS2_PRIORITYQ_H
