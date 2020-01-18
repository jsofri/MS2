//
// Created by yehonatan on 18/01/2020.
//


#include "matrix_best_fs.h"


string MatrixBestFS::search(Searchable<Point> & searchable) {
  VectorSolutionAnalyst vsa;
  string solution;

  init(searchable);

  runBestFS(searchable);

  return vsa.getSolution(close_);
}

void MatrixBestFS::init(Searchable<Point> & searchable) {
  Point null = NO_POINT;
  start_ = searchable.getInitialState();

  setMatrix(searchable);
  addToOpen(searchable, null, start_);
}

void MatrixBestFS::setMatrix(Searchable<Point> & searchable) {
  pair<unsigned int, unsigned int> size = searchable.getSize();
  unsigned int i,j;

  for (i = 0; i < size.first; i++) {
    vector<bool> row;
    for (j=0; j < size.second; j++) {
      row.push_back(false);
    }
    matrix_.addRow(row);
  }
}

void MatrixBestFS::runBestFS(Searchable<Point> & searchable) {
  while (!searchable.isGoalState(open_.front().point)) {
    list<Point> adjacents;
    BFSDN curr_bfsdn = open_.front();

    open_.erase(open_.begin());
    close_.push_back(curr_bfsdn);

    adjacents = searchable.getAllPossibleStates(curr_bfsdn.point);

    for (auto point : adjacents) {

      //not visited in point
      if (!matrix_.getCell(point)) {
        addToOpen(searchable, curr_bfsdn.point, point);
      }
    }

    sortOpenList();
  }

  close_.push_back(open_.front());
}

void MatrixBestFS::addToOpen(Searchable<Point> & searchable, Point & parent, Point & child) {
  BFSDN bfsdn;

  bfsdn.point = child;
  bfsdn.parent = parent;
  bfsdn.weight = searchable.getCost(child);
  matrix_.setCell(child, true);

  open_.push_back(bfsdn);
}

void MatrixBestFS::sortOpenList() {
  auto compare = [](BFSDN a, BFSDN b) {return a.weight < b.weight; };
  std::sort(std::begin(open_), std::end(open_), compare);
}