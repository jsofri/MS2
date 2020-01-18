//
// Created by yehonatan on 14/01/2020.
//

#include "matrix_bfs.h"
#include "matrix_solution_analyst.h"

string MatrixBFS::search(Searchable<Point> & searchable) {
  MatrixSolutionAnalyst msa;
  string solution;

  searchable_ = &searchable;

  init();

  runBFS();

  solution = msa.getSolution(amdc_matrix_, start_, end_, searchable);

  delete(queue_);

  return solution;
}

void MatrixBFS::init() {
  start_ = searchable_-> getInitialState();

  setMatrix();
  setQueue();
  amdc_matrix_[0][0].weight = 0;
  amdc_matrix_[0][0].visited = true;
}

void MatrixBFS::setMatrix() {
  int n, m;
  pair<unsigned int, unsigned int> pair = searchable_->getSize();

  makeMatrix(pair.first, pair.second);
}

//n is number of rows, m is number of columns
void MatrixBFS::makeMatrix(unsigned int & n, unsigned int & m) {
  int i, j;// i for rows, j for columns
  AMDC amdc;

  for (i = 0; i < n; i++) {
    vector<AMDC> row;

    for (j = 0; j < m; j++) {
      row.push_back(amdc);
    }

    amdc_matrix_.addRow(row);
  }
}

void MatrixBFS::setQueue() {
  Point start = searchable_->getInitialState();
  queue_ = new queue<Point *>;
  enqueue(start);
}

void MatrixBFS::enqueue(Point & point) {
  queue_->push(new Point(point));
}

Point MatrixBFS::dequeue() {
  Point * p_reference = queue_->front();
  Point point = Point(*(p_reference));

  delete(p_reference);

  queue_->pop();

  return point;
}
void MatrixBFS::runBFS() {

  while (!queue_->empty()) {
    Point point = dequeue();

    list<Point> adjs = searchable_->getAllPossibleStates(point);

    for (Point adjacent : adjs) {

      //adjacent was not visited
      if (!amdc_matrix_[adjacent.getX()][adjacent.getY()].visited) {

        amdc_matrix_[adjacent.getX()][adjacent.getY()].visited = true;

        //update parent of adjacent
        amdc_matrix_[adjacent.getX()][adjacent.getY()].parent = point;

        //update weight of adjacent
        amdc_matrix_[adjacent.getX()][adjacent.getY()].weight =
            amdc_matrix_[point.getX()][point.getY()].weight
            + searchable_->getCost(adjacent);

        enqueue(adjacent);
      }

      if (searchable_->isGoalState(point)) {
        end_ = point;
      }
    }
  }
}
