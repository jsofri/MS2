//
// Created by rony on 14/01/2020.
//

#ifndef MS2_MATRIX_DFS_H
#define MS2_MATRIX_DFS_H

#include "../objects/amdc.h"
#include "dfs.h"
#include "../objects/matrix.h"

class MatrixDFS: public DFS<Point, string> {
    void initPathMatrix();
    void recursion (Point&);
    Matrix<AMDC> path_matrix_ = Matrix<AMDC>();
    Searchable<Point>& searchable_;
public:
    string search(Searchable<Point>);
};

#endif //MS2_MATRIX_DFS_H