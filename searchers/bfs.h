//
// Created by yehonatan on 14/01/2020.
//

#ifndef BFS_ALGORITHM_H_
#define BFS_ALGORITHM_H_


#include "searcher.h"


template <typename P, typename S>
class BFS : public Searcher<P, S> {
    virtual S search(Searchable<P> &) = 0;
};

#endif //BFS_ALGORITHM_H_