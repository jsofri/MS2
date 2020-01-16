//
// Created by yehonatan on 15/01/2020.
//

#ifndef MATRIX_SEARCHABLE_H_
#define MATRIX_SEARCHABLE_H_


#include "searchable.h"
#include "objects/point.h"
#include "objects/matrix.h"


class MatrixSearchable : public Searchable<Point> {
 public:
  MatrixSearchable(Matrix<int> *);
  Point getInitialState();
  bool isGoalState(Point);
  std::list<Point> getAllPossibleStates(Point);
  std::pair<unsigned int, unsigned int> getSize();
  int getCost(Point);
 private:
  void addStates(std::list<Point>&, bool , bool, bool, bool, unsigned int &,
                 unsigned int &);
  Matrix<int> * matrix_;
  Point end_ = NO_POINT;
};

#endif //MATRIX_SEARCHABLE_H_