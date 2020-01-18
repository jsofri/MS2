//
// Created by yehonatan on 18/01/2020.
//

#ifndef SEARCHERS_MATRIX_BEST_FS_H_
#define SEARCHERS_MATRIX_BEST_FS_H_

#include "best_first_search.h"
#include <algorithm>
#include "string"
#include "queue"
#include "vector_solution_analyst.h"
#include "../objects/point.h"
#include "../objects/bfsdn.h"
#include "../objects/matrix.h"


using namespace std;


class MatrixBestFS : BestFS<Point, std::string>{
 public:
  string search(Searchable<Point> &);
 private:
  void init(Searchable<Point> &);
  void setMatrix(Searchable<Point> &);
  void runBestFS(Searchable<Point> &);
  void sortOpenList();
  void addToOpen(Searchable<Point> &, Point &, Point &);
  Matrix<bool> matrix_;
  vector<BFSDN> open_;
  vector<BFSDN> close_;
  Point start_ = NO_POINT;
  Point end_ = NO_POINT;;
};

#endif //SEARCHERS_MATRIX_BEST_FS_H_
