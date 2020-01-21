//
// Created by yehonatan on 18/01/2020.
//

#ifndef SEARCHERS_MATRIX_BEST_FS_H_
#define SEARCHERS_MATRIX_BEST_FS_H_

#include "searcher.h"
#include <algorithm>
#include "string"
#include "queue"
#include "analysts/vector_solution_analyst.h"
#include "../objects/point.h"
#include "../objects/amdc.h"
#include "../objects/matrix.h"


using namespace std;


class MatrixBestFS : public Searcher<Point, std::string>{
 public:
  string search(Searchable<Point> &);
private:
  void init(Searchable<Point> &);
  void setMatrix(Searchable<Point> &);
  void runBestFS(Searchable<Point> &);
  void sortOpenList();
  void addToOpen(Searchable<Point> &, Point &, Point &);
  Matrix<char> matrix_;
  vector<AMDC> open_;
  vector<AMDC> close_;
  Point start_ = NO_POINT;
  Point end_ = NO_POINT;;
};
#endif //SEARCHERS_MATRIX_BEST_FS_H_
