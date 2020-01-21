//
// Created by yehonatan on 18/01/2020.
//


#include "solution_analyst.h"


void SolutionAnalyst::addNodeInList(string& str) {
  list_.push_front(str);
}

string SolutionAnalyst::getString() {
  string sequence;
  stringstream string_stream;

  for (auto node : list_) {
    string_stream << node;
  }

  sequence = string_stream.str();

  return sequence;
}

void SolutionAnalyst::addWeight(double weight) {
  string token = "(";

  token += to_string((int) weight);
  token += ")";

  addNodeInList(token);
}