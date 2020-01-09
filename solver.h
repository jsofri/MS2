//
// Created by yehonatan on 09/01/2020.
//

#ifndef SOLVER_H
#define SOLVER_H
namespace server_side {
    class Solver {
        virtual Solution solve(Problem) = 0;
    };
}
#endif //SOLVER_H
