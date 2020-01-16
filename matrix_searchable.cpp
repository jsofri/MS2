//
// Created by yehonatan on 15/01/2020.
//


#include "matrix_searchable.h"


MatrixSearchable::MatrixSearchable(Matrix<int> * matrix) {
  pair<unsigned int, unsigned int> size;

  matrix_ = matrix;
  size = matrix_-> getSize();
  end_ = Point(size.first - 1, size.second - 1);
}

Point MatrixSearchable::getInitialState() {
  return Point(0,0);
}

bool MatrixSearchable::isGoalState(Point point) {
  return point == end_;
}

std::list<Point> MatrixSearchable::getAllPossibleStates(Point point) {
  list<Point> points_list;
  unsigned int x, y;
  x = point.getX();
  y = point.getY();

  if (x > 0 && (x < (end_.getX() - 1))) {
    if ((y > 0) && (y < (end_.getY() - 1))) {
      addStates(points_list, true,true,true,true,x,y);
    } else if (y == end_.getY() - 1) {
      addStates(points_list, false,true,true,true,x,y);
    } else if (y == 0) {
      addStates(points_list, true,false,true,true,x,y);
    } else {
      throw "undefined Point object";
    }
  } else if (x == 0) {
    if ((y > 0) && (y < (end_.getY() - 1))) {
      addStates(points_list, true,true,false,true,x,y);
    } else if (y == end_.getY() - 1) {
      addStates(points_list, false,true,false,true,x,y);
    } else if (y == 0) {
      addStates(points_list, true,false,false,true,x,y);
    } else {
      throw "undefined Point object";
    }
  } else if (x == (end_.getX() - 1)) {
    if ((y > 0) && (y < (end_.getY() - 1))) {
      addStates(points_list, true,true,true,false,x,y);
    } else if (y == end_.getY()) {
      addStates(points_list, false,true,true,false,x,y);
    } else if (y == 0) {
      addStates(points_list, true,true,false,false,x,y);
    } else {
      throw "undefined Point object";
    }
  } else {
    throw "undefined Point object";
  }

  return points_list;
}

void MatrixSearchable::addStates(std::list<Point>& list, bool right,
               bool left, bool up, bool down, unsigned int & x, unsigned int & y) {
  if (right) {
    list.push_back(Point(x, y + 1));
  }

  if (left) {
    list.push_back(Point(x, y - 1));
  }

  if(up) {
    list.push_back(Point(x-1, y));
  }

  if (down) {
    list.push_back(Point(x + 1, y));
  }
}

std::pair<unsigned int, unsigned int> MatrixSearchable::getSize() {
  return matrix_->getSize();
}

int MatrixSearchable::getCost(Point p) {
  return (*matrix_)[p.getX()][p.getY()];
}