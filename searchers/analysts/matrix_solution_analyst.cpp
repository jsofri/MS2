//
// Created by yehonatan on 15/01/2020.
//


#include "matrix_solution_analyst.h"


std::string MatrixSolutionAnalyst::getSolution(Matrix<AMDC>& matrix, Point& start, Point& end, Searchable<Point>& searchable) {
  AMDC amdc;
  Point path_point = end;

  if (start == end) {
      string result = "You're already there, honey!\n";
      return result;
  }

  matrix_ = matrix;
  do {
    amdc = matrix.getCell(path_point);

    addWeight(amdc.weight);
    addDirection(amdc.parent, path_point);
    point_map_[path_point.to_string()] = true;

    path_point = matrix.getCell(path_point).parent;
  } while (path_point != start);

    //printMarkedPath(searchable);

  return getString();
}

string MatrixSolutionAnalyst::printMarkedPath (Searchable<Point>& searchable) {
    string result;
    for (auto row : matrix_.getMatrix()) {
        for (auto amdc : row) {
            if (point_map_.count(amdc.myself.to_string())) {
                result += "*";
            }
            result += to_string(searchable.getCost(amdc.myself));
            result += ", ";
        }
        result += "\n";
    }

    result += '\n' + getString();

    return result;
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
