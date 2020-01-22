//
// Created by yehonatan on 14/01/2020.
//

#ifndef OBJECTS_POINT_H_
#define OBJECTS_POINT_H_

#define NO_POINT Point(-1, -1)
#include <string>


class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}
  unsigned int getX();
  unsigned int getY();
  bool operator==(Point);
  bool operator!=(Point);
  std::string to_string();
  unsigned long toHash();
 private:
  unsigned int x_;
  unsigned int y_;
};

#endif //OBJECTS_POINT_H_