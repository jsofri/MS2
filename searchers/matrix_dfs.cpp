//
// Created by rony on 14/01/2020.
//

#include "matrix_dfs.h"

string MatrixDFS::search(Searchable<Point>& searchable) {
    MatrixSolutionAnalyst msa;
    string solution;
    searchable_ = &searchable;
    traversed_vertex_counter_ = 0;

    // initialize the path matrix
    initPathMatrix();

    // update the initial cell
    auto initial = searchable.getInitialState();
    unsigned int x = initial.getX();
    unsigned int y = initial.getY();
    path_matrix_[x][y].visited = true;
    path_matrix_[x][y].weight = searchable_ -> getCost(initial);

    // do the recursion
    recursion(initial);

    // return solution
    solution = msa.getSolution(path_matrix_, initial, *end_, *searchable_);
    return solution;
}

void MatrixDFS::recursion(Point& currentPoint) {
    traversed_vertex_counter_++;

    // check if we reached the goal point
    if (searchable_ -> isGoalState(currentPoint)) {
        end_ = new Point(currentPoint);
        return;
    }

    auto neighbors = searchable_ -> getAllPossibleStates(currentPoint);
    for (Point neighbor: neighbors) {
        unsigned int x = neighbor.getX();
        unsigned int y = neighbor.getY();
        if (!path_matrix_[x][y].visited) {
            // mark cell as visited
            path_matrix_[x][y].visited = true;
            path_matrix_[x][y].parent = currentPoint;
            path_matrix_[x][y].weight = searchable_ -> getCost(neighbor) + path_matrix_.getCell(currentPoint).weight;

            // continue the recursion
            recursion(neighbor);
        }
    }
}

/**
 * initialize the path matrix
 * @param searchable
 * @return
 */
void MatrixDFS::initPathMatrix() {
    for (int i = 0; i < searchable_ -> getSize().first; ++i) {
        vector<AMDC> row;
        path_matrix_.addRow(row);

        for (int j = 0; j < searchable_ -> getSize().second; ++j) {
            auto cell = AMDC();
            path_matrix_[i].push_back(cell);
        }
    }
}

/**
 * Destructor
 */
MatrixDFS::~MatrixDFS() {
  delete end_;
}

void MatrixDFS::printMatrix() {
  for (int i = 0; i < path_matrix_.getSize().first; i++) {
    for (int j = 0; j < path_matrix_.getSize().first; j++) {
      auto cell = path_matrix_.getCell(Point(i, j));
      cout << cell.weight << " (" << cell.parent.getX() << ", " << cell.parent.getY() <<") | ";
    }
    cout << endl;

  }
}