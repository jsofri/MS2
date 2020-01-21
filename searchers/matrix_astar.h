//
// Created by rony on 17/01/2020.
//

#ifndef MATRIX_ASTAR_H
#define MATRIX_ASTAR_H

#include "../objects/point.h"
#include "searcher.h"
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include "../objects/point.h"
#include "../objects/amdc.h"
#include "../objects/matrix.h"
#include "../objects/priority_q.h"

#define TYPE AMDC*

using namespace std;

struct ComparePriority {
    bool operator()(TYPE p1, TYPE p2)
    {
        // return "true" if "p1" is ordered before "p2"
        return p1 -> weightH > p2 -> weightH;
    }
};

class MatrixAStar : public Searcher<Point, string> {
public:
    MatrixAStar() = default;
    string search(Searchable<Point> &) override;
private:
    void runAStar();
    void pushNeighborsOf(Point);
    void initPathMatrix();
    void init();
    static unsigned int distance(Point, Point);
    Matrix<AMDC> path_matrix_;
    PriorityQ<TYPE> open_;
    Searchable<Point>* searchable_;
    unordered_map<string, PriorityQ<TYPE>::iterator> open_map_;
    unordered_map<string, bool> close_;
};


#endif //MATRIX_ASTAR_H
