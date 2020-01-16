//
// Created by rony on 14/01/2020.
//

#include <objects/amdc.h>
#include "matrix_dfs.h"

string MatrixDFS::search(Searchable<Point> searchable) {
    searchable_ = searchable;

    // initialize the path matrix
    initPathMatrix();

    // update the initial cell
    auto initial = searchable.getInitialState();
    unsigned int x = initial.getX();
    unsigned int y = initial.getY();
    path_matrix_[x][y].visited = true;
    path_matrix_[x][y].weight = searchable_.getCost(initial);

    // do the recursion
    recursion(initial);

}

void MatrixDFS::recursion (Point& currentPoint) {
    auto neighbors = searchable_.getAllPossibleStates(currentPoint);
    for (Point neighbor: neighbors) {
        unsigned int x = neighbor.getX();
        unsigned int y = neighbor.getY();
        if (!path_matrix_[x][y].visited) {
            // mark cell as visited
            path_matrix_[x][y].visited = true;
            path_matrix_[x][y].parent = currentPoint;
            path_matrix_[x][y].weight = searchable_.getCost(neighbor) + searchable_.getCost(currentPoint);

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
    for (int i = 0; i < searchable_.getSize().first; ++i) {
        vector<AMDC> row;
        path_matrix_.addRow(row);

        for (int j = 0; j < searchable_.getSize().second; ++j) {
            auto cell = AMDC();
            path_matrix_[i].push_back(cell);
        }
    }
}