//
// Created by rony on 12/01/2020.
//

#ifndef MS2_SOLVER_H
#define MS2_SOLVER_H


namespace server_side {
    template<typename K, typename V>
    class Solver {
    public:
        virtual V solve(K) = 0;
    };
}

#endif //MS2_SOLVER_H
