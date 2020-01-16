//
// Created by yehonatan on 15/01/2020.
//

#ifndef SEARCHERS_SOLUTION_ANALYST_H_
#define SEARCHERS_SOLUTION_ANALYST_H_

//get some kind of solution - T, goal and start state - U
//return a specific output from it - S.
//e.g. get matrix of solution - T, get goal and start state - U
//and return a string - S
template <typename T, typename U, typename S>
class SolutionAnalyst {
 public:
  virtual S getSolution(U, T, T) = 0;
};

#endif //SEARCHERS_SOLUTION_ANALYST_H_
