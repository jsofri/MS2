//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_SEARCHERS_MATRIX_BFS_H_
#define MS2_SEARCHERS_MATRIX_BFS_H_


#include <queue>
#include "../objects/point.h"
#include "../searchable.h"
#include "breadth_first_search.h"


class MatrixBFS : BreadthFirstSearch<Point, string> {
 public:
  string search(Searchable<Point> &);
 private:
  void init();
  string runBFS(Searchable<Point> &);
  string stringFromSolution();
  std::queue<unsigned int> * queue_;//each vertex is a number
  Matrix parent_and_value_;//first is parent, second is value
};

#endif //MS2_SEARCHERS_MATRIX_BFS_H_
