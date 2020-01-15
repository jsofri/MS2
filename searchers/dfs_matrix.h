//
// Created by rony on 14/01/2020.
//

#ifndef MS2_DFS_MATRIX_H
#define MS2_DFS_MATRIX_H

#include "dfs.h"
#include "../objects/matrix.h"

class MatrixDFS: public DFS<Searchable<Point>, string> {
    string search(Searchable<Point>);
};


#endif //MS2_DFS_MATRIX_H
