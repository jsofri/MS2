//
// Created by yehonatan on 15/01/2020.
//

#ifndef SEARCHERS_SOLUTION_ANALYST_H_
#define SEARCHERS_SOLUTION_ANALYST_H_

#include <list>
#include <string>
#include <sstream>

using namespace std;

class SolutionAnalyst {
 protected:
  void addWeight(double);
  void addNodeInList(string &);
  string getString();
  list<string> list_;
};

#endif //SEARCHERS_SOLUTION_ANALYST_H_
