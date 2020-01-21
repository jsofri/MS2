//
// Created by rony on 14/01/2020.
//

#ifndef MS2_MATRIX_DFS_H
#define MS2_MATRIX_DFS_H


#include "searcher.h"
#include "../objects/matrix.h"
#include "../objects/amdc.h"
#include "analysts/matrix_solution_analyst.h"
#include "../searchables/searchable.h"
#include "searcher.h"


class MatrixDFS: public Searcher<Point, string> {
public:
    string search(Searchable<Point> &) override;
    ~MatrixDFS();
private:
    void initPathMatrix();
    void recursion (Point&);
    void printMatrix();
    Matrix<AMDC> path_matrix_ = Matrix<AMDC>();
    Searchable<Point>* searchable_;
    Point* end_;
};


#endif //MS2_MATRIX_DFS_H