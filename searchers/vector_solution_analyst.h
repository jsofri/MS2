//
// Created by yehonatan on 18/01/2020.
//

#ifndef SEARCHERS_VECTOR_SOLUTION_ANALYST_H_
#define SEARCHERS_VECTOR_SOLUTION_ANALYST_H_

#include "vector"
#include "solution_analyst.h"
#include "../objects/point.h"
#include "../objects/bfsdn.h"

using namespace std;

/**
 * object of this type get a vector from a best first search algorithm,
 * and return a string that represents the solution of the algorithm,
 * meaning what are the steps from start to goal position.
 */
class VectorSolutionAnalyst : SolutionAnalyst {
 public:
  string getSolution(vector<BFSDN>);
 private:
  double sumWeight(vector<BFSDN> &);
  void addDirection(BFSDN);
  void handleLastNode(BFSDN);
  Point start_ = NO_POINT;
};

#endif //SEARCHERS_VECTOR_SOLUTION_ANALYST_H_
