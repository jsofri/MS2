//
// Created by yehonatan on 14/01/2020.
//

#ifndef SEARCHER_H_
#define SEARCHER_H_

#include "../searchables/searchable.h"

template <typename P, typename S>
class Searcher {
public:
    virtual S search(Searchable<P> &) = 0;
};

#endif //SEARCHER_H_