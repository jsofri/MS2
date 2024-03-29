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

std::string Point::to_string() {
  std::string str = "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  return str;
}

unsigned long Point::toHash() {
    std::hash<std::string> hash_f;

    return hash_f(this->to_string());
}