//
// Created by Rony on 14/01/2020.
//

#ifndef DFS_ALGORITHM_H_
#define DFS_ALGORITHM_H_

#include "searcher.h"
#include "../objects/matrix.h"

template <typename P, typename S>
class DFS : public Searcher<P, S> {
    virtual S search(P) = 0;
};

#endif //DFS_ALGORITHM_H_
