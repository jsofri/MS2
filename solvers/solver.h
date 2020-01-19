//
// Created by yehonatan on 09/01/2020.
//

#ifndef SOLVER_H
#define SOLVER_H



template <typename K, typename V>
class Solver {
    virtual V solve(K &) = 0;
};
#endif //SOLVER_H
