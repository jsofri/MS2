//
// Created by yehonatan on 14/01/2020.
//

#include "matrix_bfs.h"

string MatrixBFS::search(Searchable<Point> & searchable) {
  string solution;

  init(searchable);

  string = runBFS();

  delete(queue_);
}

void MatrixBFS::init(Searchable<Point> & searchable) {
  //set data structures - queue
  //set color and distance of each vertex
}

string MatrixBFS::runBFS(Matrix &) {
  //if got to goal state - set and string
}

string MatrixBFS::stringFromSolution(Matrix &) {

}