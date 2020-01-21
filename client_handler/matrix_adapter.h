//
// Created by yehonatan on 21/01/2020.
//

#ifndef MATRIX_ADAPTER_H_
#define MATRIX_ADAPTER_H_

#include "../searchables/searchable.h"
#include "../objects/point.h"
#include "../solvers/solver.h"
#include "../searchers/matrix_astar.h"


using namespace std;


class MatrixAdapter : public Solver<Searchable<Point>, string> {
 public:
  string solve(Searchable<Point> &);
};

#endif //MATRIX_ADAPTER_H_
