//
// Created by yehonatan on 18/01/2020.
//

#ifndef MS2_OBJECTS_BFSDN_H_
#define MS2_OBJECTS_BFSDN_H_

#include <cmath>
#include "point.h"


//BFSDN is a best first search data node
//similar to AMDC, yet contains a self Point "point"
typedef struct BFSDN {
  Point point = NO_POINT;
  Point parent  = NO_POINT;
  double weight = HUGE_VAL;;
} BFSDN;

#endif //MS2_OBJECTS_BFSDN_H_
