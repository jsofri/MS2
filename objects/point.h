//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_OBJECTS_POINT_H_
#define MS2_OBJECTS_POINT_H_

#define NO_POINT Point(-1, -1)

class Point {
 public:
  Point(unsigned int x, unsigned int y) : x_(x), y_(y) {}
  unsigned int getX();
  unsigned int getY();
  bool operator==(Point);
  bool operator!=(Point);
 private:
  unsigned int x_;
  unsigned int y_;
};

#endif //MS2_OBJECTS_POINT_H_