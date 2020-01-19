//
// Created by yehonatan on 14/01/2020.
//

#ifndef SEARCHABLE_H_
#define SEARCHABLE_H_


#include "list"


template<typename P>
class Searchable {
 public:
  virtual P getInitialState() = 0;
  virtual bool isGoalState(P) = 0;
  virtual P getGoalState() = 0;
  virtual std::list<P> getAllPossibleStates(P) = 0;
  virtual std::pair<unsigned int, unsigned int> getSize() = 0;
  virtual int getCost(P) = 0;
};

#endif //SEARCHABLE_H_