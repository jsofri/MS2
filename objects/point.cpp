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