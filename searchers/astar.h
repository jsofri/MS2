//
// Created by rony on 17/01/2020.
//

#ifndef MS2_ASTAR_H
#define MS2_ASTAR_H

#include "searcher.h"

template <typename P, typename S>
class AStar: public Searcher<P, S> {
    virtual S search(Searchable<P> &) = 0;
};


#endif //MS2_ASTAR_H
