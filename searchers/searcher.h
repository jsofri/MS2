//
// Created by yehonatan on 14/01/2020.
//

#ifndef SEARCHER_H_
#define SEARCHER_H_

template <typename P, typename S>
class Searcher {
 public:
    virtual S search(P) = 0;
};

#endif //SEARCHER_H_
