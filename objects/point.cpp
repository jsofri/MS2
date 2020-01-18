//
// Created by yehonatan on 14/01/2020.
//

#include "point.h"

unsigned int Point::getX() {
  return x_;
}

unsigned int Point::getY() {
  return y_;
}

bool Point::operator==(Point p) {
  return ((x_ == p.x_) && (y_ == p.y_));
}

bool Point::operator!=(Point p) {
  return ((x_ != p.x_) || (y_ != p.y_));
}
/*bool Point::operator=(Point p) {
  x_ = p.x_;
  y_ = p.y_;

  return 1;
}*/

std::string Point::toString() {
  uint64_t i64;
  uint32_t a32, b32;
  a32 = x_;
  b32 = y_;

  i64 = ((uint64_t)a32 << 32) | b32;

  return std::to_string(i64);
}