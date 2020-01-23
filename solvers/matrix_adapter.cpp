//
// Created by yehonatan on 21/01/2020.
//

#include "matrix_adapter.h"
#define CHOSEN_ALGO MatrixAStar

using namespace std;


string MatrixAdapter::solve(Searchable<Point> & searchable) {
    CHOSEN_ALGO algo;
    string solution;

    solution = algo.search(searchable);

    return solution;
}