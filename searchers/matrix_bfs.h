//
// Created by yehonatan on 14/01/2020.
//

#ifndef SEARCHERS_MATRIX_BFS_H_
#define SEARCHERS_MATRIX_BFS_H_


#include <queue>
#include "../objects/point.h"
#include "../objects/amdc.h"
#include "../objects/matrix.h"
#include "../searchables/searchable.h"
#include "searcher.h"

class MatrixBFS : public Searcher<Point, string> {
 public:
  string search(Searchable<Point> &);
private:
  void init(Searchable<Point> &);
  void runBFS(Searchable<Point> &);
  void setMatrix(Searchable<Point> &);
  void makeMatrix(unsigned int &, unsigned int &);
  void setQueue(Searchable<Point> &);
  Point dequeue();
  void enqueue(Point &);
  std::queue<Point *> * queue_;//each vertex is a point
  Matrix<AMDC> amdc_matrix_;  //first is parent, second is value
  Point start_ = NO_POINT;
  Point end_ = NO_POINT;
  //Searchable<Point> * searchable_;
};

#endif //SEARCHERS_MATRIX_BFS_H_
