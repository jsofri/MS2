//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_SEARCHERS_BFS_MATRIX_H_
#define MS2_SEARCHERS_BFS_MATRIX_H_

#include "breadth_first_search.h"

class MatrixBFS : BreadthFirstSearch<Matrix, string> {
  string search(Matrix);
};

#endif //MS2_SEARCHERS_BFS_MATRIX_H_
