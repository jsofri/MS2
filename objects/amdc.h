//
// Created by yehonatan on 15/01/2020.
//

#ifndef OBJECTS_AMDC_H_
#define OBJECTS_AMDC_H_

#include <string>
#include <cmath>
#include "point.h"

//AMDC is Algorithem Matrix Data Cell - we use it for BFS, DFS etc.
//initialized to have no parent point and infinity value
typedef struct AMDC {
  Point myself = NO_POINT;
  Point parent = NO_POINT;
  double weight = HUGE_VAL;
  double weightH = HUGE_VAL; // with heuristic
  bool visited = false;

  std::string to_string() {
      return myself.to_string() + parent.to_string() + std::to_string(weight) +
             std::to_string(weightH) + std::to_string(visited);
  }

} AMDC;

#endif //OBJECTS_AMDC_H_
