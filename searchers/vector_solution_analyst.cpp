//
// Created by yehonatan on 18/01/2020.
//


#include "vector_solution_analyst.h"

/**
 * reconstruct a solution of best first search from vector.
 * @param vector "close" of best first search algorithm after end of algorithm
 * @return string that represents the steps for the goal state
 */
string VectorSolutionAnalyst::getSolution(vector<BFSDN> vector) {
  int i, weight = sumWeight(vector);
  string str;
  Point next = vector.back().point;

  if (vector.size() == 1) {
    string solution = "None";
    solution += to_string((int) vector[0].weight);
    return solution;
  }

  start_ = vector[0].point;

  for (i = vector.size() - 1; i > 0; i--) {
    if (next == vector[i].point) {
      addWeight(weight);
      addDirection(vector[i]);
      next = vector[i].parent;
      weight -= vector[i].weight;
    }
  }

  return getString();
}

/**
 * add to list_ string of direction
 *
 * @param bfsdn a BFSDN struct
 */
void VectorSolutionAnalyst::addDirection(BFSDN bfsdn) {
  string str = ", ";

  if (bfsdn.parent == start_) {
    handleLastNode(bfsdn);
    return;
  }

  if (bfsdn.parent.getX() == bfsdn.point.getX()) {
    if (bfsdn.parent.getY() == bfsdn.point.getY()) {
      str += "None ";
    } else if (bfsdn.parent.getY() < bfsdn.point.getY()) {
      str += "Right ";
    } else {
      str += "Left ";
    }
  } else if (bfsdn.parent.getX() > bfsdn.point.getX()){
    str += "Up ";
  } else {
    str += "Down ";
  }

  addNodeInList(str);
}

/**
 * helper method to know the first step in algorithm.
 *
 * @param bfsdn BFSDN of the second vertex in the solution.
 */
void VectorSolutionAnalyst::handleLastNode(BFSDN bfsdn) {
  Point point = bfsdn.point;
  string str = "";

  if (point.getX() == start_.getX())
    if (point.getY() > start_.getY()) {
      str += "Right ";
    } else if (point.getY() < start_.getY()) {
      str += "Left ";
    } else {
      throw "something's wrong in vector input";
    }
  else if (point.getY() == start_.getY()) {
    if (point.getX() > start_.getX()) {
      str += "Down ";
    } else if (point.getX() < start_.getX()) {
      str += "Up ";
    } else {
      throw "something's wrong in vector input";
    }
  } else {
    throw "something's wrong in vector input";
  }

  addNodeInList(str);
}

/**
 * summerize the total weight of the solution.
 *
 * @param vector "close" vector from best first search algorithm.
 * @return double - weight of path.
 */
double VectorSolutionAnalyst::sumWeight(vector<BFSDN> & vector) {
  int i, weight = vector.back().weight;
  Point next = vector.back().parent;

  for (i = vector.size() - 1; i >= 0; i--) {
    if (vector[i].point == next) {
      next = vector[i].parent;
      weight += vector[i].weight;
    }
  }

  return weight;
}