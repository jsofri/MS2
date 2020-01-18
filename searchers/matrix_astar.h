//
// Created by rony on 17/01/2020.
//

#ifndef MS2_MATRIX_ASTAR_H
#define MS2_MATRIX_ASTAR_H

#include <objects/point.h>
#include "astar.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <objects/amdc.h>
#include <objects/matrix.h>
#include <objects/PriorityQ.h>

using namespace std;

class MatrixAStar: public AStar<Point, string> {
public:
    MatrixAStar() = default;
    string search(Searchable<Point> &) override;
private:
    void runAStar();
    void pushNeighborsOf(Point);
    static unsigned int distance(Point, Point);
    void initPathMatrix();
    Matrix<AMDC> path_matrix_;
    PriorityQ<double, AMDC> queue_;
    Searchable<Point>* searchable_;
    unordered_map<string, bool> map_;
};


#endif //MS2_MATRIX_ASTAR_H
