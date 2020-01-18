//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_SEARCHERS_MATRIX_BFS_H_
#define MS2_SEARCHERS_MATRIX_BFS_H_


#include <queue>
#include "../objects/point.h"
#include "../objects/amdc.h"
#include "../objects/matrix.h"
#include "searchables/searchable.h"
#include "bfs.h"

class MatrixBFS : BFS<Point, string> {
 public:
  string search(Searchable<Point> &);
 private:
  void init();
  void runBFS();
  void setMatrix();
  void makeMatrix(unsigned int &, unsigned int &);
  void setQueue();
  Point dequeue();
  void enqueue(Point &);
  std::queue<Point *> * queue_;//each vertex is a point
  Matrix<AMDC> amdc_matrix_;  //first is parent, second is value
  Point start_ = NO_POINT;
  Point end_ = NO_POINT;
  Searchable<Point> * searchable_;
};

#endif //MS2_SEARCHERS_MATRIX_BFS_H_
