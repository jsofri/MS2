//
// Created by yehonatan on 14/01/2020.
//

#include "matrix_bfs.h"
#include "analysts/matrix_solution_analyst.h"

string MatrixBFS::search(Searchable<Point> & searchable) {
  MatrixSolutionAnalyst msa;
  string solution;

  init(searchable);

  runBFS(searchable);

  solution = msa.getSolution(amdc_matrix_, start_, end_, searchable);

  delete(queue_);

  return solution;
}

void MatrixBFS::init(Searchable<Point> & searchable) {
    traversed_vertex_counter_ = 0;
    start_ = searchable.getInitialState();

  setMatrix(searchable);
  setQueue(searchable);
  amdc_matrix_[0][0].weight = 0;
  amdc_matrix_[0][0].visited = true;
}

void MatrixBFS::setMatrix(Searchable<Point> & searchable) {
  int n, m;
  pair<unsigned int, unsigned int> pair = searchable.getSize();

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

void MatrixBFS::setQueue(Searchable<Point> & searchable) {
  Point start = searchable.getInitialState();
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
void MatrixBFS::runBFS(Searchable<Point> & searchable) {

  while (!queue_->empty()) {
    traversed_vertex_counter_++;

    Point point = dequeue();

    if (searchable.isGoalState(point)) {
        end_ = point;
        return;
    }

    list<Point> adjs = searchable.getAllPossibleStates(point);

    for (Point adjacent : adjs) {
      //adjacent was not visited
      unsigned int x = adjacent.getX();
      unsigned int y = adjacent.getY();
      if (!amdc_matrix_[x][y].visited) {
        amdc_matrix_[x][y].visited = true;
        //update parent of adjacent
        amdc_matrix_[x][y].parent = point;
        //update weight of adjacent
        amdc_matrix_[x][y].weight = amdc_matrix_[point.getX()][point.getY()].weight + searchable.getCost(adjacent);

        enqueue(adjacent);
      }
    }
  }

}
