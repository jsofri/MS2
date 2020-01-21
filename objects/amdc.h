//
// Created by yehonatan on 15/01/2020.
//

#ifndef MS2_OBJECTS_AMDC_H_
#define MS2_OBJECTS_AMDC_H_

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
} AMDC;

#endif //MS2_OBJECTS_AMDC_H_
