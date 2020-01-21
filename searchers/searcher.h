//
// Created by yehonatan on 14/01/2020.
//

#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "../searchables/searchable.h"
#include <string>

template <typename P, typename S>
class Searcher {
public:
    virtual S search(Searchable<P> &) = 0;
    unsigned int getTraversedVerixes() {
        return traversed_vertex_counter_;
    }

protected:
    unsigned int traversed_vertex_counter_ = 0;
};

#endif //SEARCHER_H_