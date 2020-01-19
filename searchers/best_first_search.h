//
// Created by yehonatan on 18/01/2020.
//

#ifndef SEARCHERS_BEST_FIRST_SEARCH_H_
#define SEARCHERS_BEST_FIRST_SEARCH_H_

#include "searcher.h"


template <typename P, typename S>
class BestFS : public Searcher<P,S> {
  virtual S search(Searchable<P> &) = 0;
};
#endif //SEARCHERS_BEST_FIRST_SEARCH_H_
