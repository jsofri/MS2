//
// Created by yehonatan on 14/01/2020.
//

#ifndef BFS_ALGORITHM_H_
#define BFS_ALGORITHM_H_


#include <cmath>
#include "searcher.h"
#include "../objects/matrix.h"


typedef struct BFSCell {
  Point parent = NO_POINT;
  double weight = HUGE_VAL;
} node ;

template <typename P, typename S>
class BreadthFirstSearch : public Searcher<P, S> {
  virtual S search(P) = 0;
};

#endif //BFS_ALGORITHM_H_
