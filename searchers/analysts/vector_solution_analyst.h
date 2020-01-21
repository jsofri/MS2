//
// Created by yehonatan on 18/01/2020.
//

#ifndef SEARCHERS_VECTOR_SOLUTION_ANALYST_H_
#define SEARCHERS_VECTOR_SOLUTION_ANALYST_H_

#include "vector"
#include "solution_analyst.h"
#include "../../objects/point.h"
#include "../../objects/amdc.h"

using namespace std;

/**
 * object of this type get a vector from a best first search algorithm,
 * and return a string that represents the solution of the algorithm,
 * meaning what are the steps from start to goal position.
 */
class VectorSolutionAnalyst : SolutionAnalyst {
 public:
  string getSolution(vector<AMDC>&);
 private:
  double sumWeight(vector<AMDC> &);
  void addDirection(AMDC&);
  void handleLastNode(AMDC&);
  Point start_ = NO_POINT;
};

#endif //SEARCHERS_VECTOR_SOLUTION_ANALYST_H_
