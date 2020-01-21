//
// Created by yehonatan on 21/01/2020.
//

#include "matrix_adapter.h"

using namespace std;


string MatrixAdapter::solve(Searchable<Point> & searchable) {
    MatrixAStar matrix_astar;
    string solution;

    solution = matrix_astar.search(searchable);

    return solution;
}