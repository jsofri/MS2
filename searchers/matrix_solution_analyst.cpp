//
// Created by yehonatan on 15/01/2020.
//


#include "matrix_solution_analyst.h"


std::string MatrixSolutionAnalyst::getSolution(Matrix<AMDC>& matrix, Point& start, Point& end) {
  AMDC amdc;
  Point path_point = end;

  matrix_ = matrix;
  do {
    amdc = matrix.getCell(path_point);

    addWeight(amdc.weight);
    addDirection(amdc.parent, path_point);

    path_point = matrix.getCell(path_point).parent;
  } while (path_point != start);

  return getString();
}

void MatrixSolutionAnalyst::addDirection(Point & parent, Point & child) {
  string str = "";

  //no prior point tp parent => last point, no need for ", " precedence
  if (matrix_.getCell(parent).parent != NO_POINT) {
    str += ", ";
  }

  if (parent.getX() == child.getX()) {
    if (parent.getY() == child.getY()) {
      str += "None ";
    } else if (parent.getY() < child.getY()) {
      str += "Right ";
    } else {
      str += "Left ";
    }
  } else if (parent.getX() > child.getX()){
    str += "Up ";
  } else {
    str += "Down ";
  }

  addNodeInList(str);
}