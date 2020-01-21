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
#include <sstream>
#include <unordered_map>
#include "../searchables/searchable.h"


class MatrixSolutionAnalyst : public SolutionAnalyst {
 public:
  std::string getSolution(Matrix<AMDC>&, Point&, Point&, Searchable<Point>&);
 private:
  void addDirection(Point &, Point &);
  Matrix<AMDC> matrix_;
  unordered_map<string, bool> point_map_;
};

#endif //SEARCHERS_MATRIX_SOLUTION_ANALYST_H_
