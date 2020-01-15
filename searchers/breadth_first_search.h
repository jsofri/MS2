//
// Created by yehonatan on 14/01/2020.
//

#ifndef BFS_ALGORITHM_H_
#define BFS_ALGORITHM_H_


#include "searcher.h"


template <typename P, typename S>
class BreadthFirstSearch : public Searcher<P, S> {
  virtual S search(P) = 0;
};

#endif //BFS_ALGORITHM_H_
