//
// Created by yehonatan on 15/01/2020.
//

#ifndef MS2_SEARCHERS_MATRIX_SOLUTION_ANALYST_H_
#define MS2_SEARCHERS_MATRIX_SOLUTION_ANALYST_H_


#include <string>
#include <list>
#include "solution_analyst.h"
#include "../objects/amdc.h"
#include "../objects/matrix.h"
#include "cstring"


class MatrixSolutionAnalyst : public SolutionAnalyst {
 public:
  std::string getSolution(Matrix<AMDC>&, Point&, Point&);
 private:
  void addDirection(Point &, Point &);
  Matrix<AMDC> matrix_;
};

#endif //SEARCHERS_MATRIX_SOLUTION_ANALYST_H_
