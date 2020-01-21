//
// Created by yehonatan on 15/01/2020.
//


#include "matrix_searchable.h"

MatrixSearchable::MatrixSearchable(Matrix<int> matrix, Point start, Point end) {
    matrix_ = matrix;
    start_ = start;
    end_ = end;
}

MatrixSearchable::MatrixSearchable(Matrix<int> matrix) {
  pair<unsigned int, unsigned int> size;

  matrix_ = matrix;
  size = matrix.getSize();
  end_ = Point(size.first - 1, size.second - 1);
}

Point MatrixSearchable::getInitialState() {
  return start_;
}

bool MatrixSearchable::isGoalState(Point point) {
  return point == end_;
}

Point MatrixSearchable::getGoalState() {
  return end_;
}

std::list<Point> MatrixSearchable::getAllPossibleStates(Point point) {
  list<Point> points_list;
  unsigned int x, y;
  x = point.getX();
  y = point.getY();

  if (x > 0 && (x < end_.getX())) {
    if ((y > 0) && (y < end_.getY())) {
      addStates(points_list, true,true,true,true,x,y);
    } else if (y == end_.getY()) {
      addStates(points_list, false,true,true,true,x,y);
    } else if (y == 0) {
      addStates(points_list, true,false,true,true,x,y);
    } else {
      throw "undefined Point object";
    }
  } else if (x == 0) {
    if ((y > 0) && (y < end_.getY())) {
      addStates(points_list, true,true,false,true,x,y);
    } else if (y == end_.getY()) {
      addStates(points_list, false,true,false,true,x,y);
    } else if (y == 0) {
      addStates(points_list, true,false,false,true,x,y);
    } else {
      throw "undefined Point object";
    }
  } else if (x == end_.getX()) {
    if ((y > 0) && (y < end_.getY())) {
      addStates(points_list, true,true,true,false,x,y);
    } else if (y == end_.getY()) {
      addStates(points_list, false,true,true,false,x,y);
    } else if (y == 0) {
      addStates(points_list, true,false,true,false,x,y);
    } else {
      throw "undefined Point object";
    }
  } else {
    throw "undefined Point object";
  }
  // remove all walls
  removeAllWalls(points_list);

  return points_list;
}

void MatrixSearchable::removeAllWalls(list<Point> points_list) {
    auto iter = points_list.begin();
    auto end = points_list.end();
    while (iter != end) {
        if (getCost(*iter) == -1) {
            iter = points_list.erase(iter);
        } else {
            iter++;
        }
    }
}

void MatrixSearchable::addStates(std::list<Point>& list, bool right,
               bool left, bool up, bool down, unsigned int & x, unsigned int & y) {
  if (right && matrix_.getCell(Point(x, y + 1)) != -1) {
    list.push_back(Point(x, y + 1));
  }

  if (left && matrix_.getCell(Point(x, y - 1)) != -1) {
    list.push_back(Point(x, y - 1));
  }

  if(up && matrix_.getCell(Point(x - 1, y)) != -1) {
    list.push_back(Point(x-1, y));
  }

  if (down && matrix_.getCell(Point(x + 1, y)) != -1) {
    list.push_back(Point(x + 1, y));
  }
}

std::pair<unsigned int, unsigned int> MatrixSearchable::getSize() {
  return matrix_.getSize();
}

int MatrixSearchable::getCost(Point p) {
  return matrix_[p.getX()][p.getY()];
}