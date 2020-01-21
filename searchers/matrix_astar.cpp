//
// Created by rony on 17/01/2020.
//

#include <cmath>
#include "matrix_astar.h"
#include "analysts/matrix_solution_analyst.h"

string MatrixAStar::search(Searchable<Point>& searchable) {
    MatrixSolutionAnalyst msa;
    string solution;
    searchable_ = &searchable;
    traversed_vertex_counter_ = 0;

    // initialize the path matrix
    initPathMatrix();

    // init: push first vertex to queue
    init();

    try {
        runAStar();
    } catch (const char * exception) {
        cerr << exception << endl;
    }

    // return solution
    auto initial = searchable_ -> getInitialState();
    auto end = searchable_ -> getGoalState();
    solution = msa.getSolution(path_matrix_, initial, end, searchable);
    return solution;
}

void MatrixAStar::init () {
    auto initial = searchable_ -> getInitialState();
    AMDC& initial_amdc = path_matrix_.getCell(initial);
    initial_amdc.weight = searchable_ -> getCost(initial);

    double priority = initial_amdc.weight + distance(initial, searchable_ -> getGoalState());
    initial_amdc.weightH = priority;
    //auto pr = pair<double, AMDC&>(priority, initial_amdc);
    open_.push_front(&initial_amdc);
    open_map_[initial.toString()] = open_.begin();
    open_.sort();
}

void MatrixAStar::runAStar() {
    while (!open_.empty()) {
        traversed_vertex_counter_++;

        auto top = open_.front() -> myself;
        // cout << top.toString() << " " << path_matrix_.getCell(top).weight << endl;

        // check if goal has been reached
        if (searchable_->isGoalState(top)) {
            return;
        }

        // remove top from priority queue and map
        open_.pop_front();
        open_map_.erase(top.toString());

        // push neighbors
        pushNeighborsOf(top);

        // add to closed list
        close_[top.toString()] = true;
    }

    throw "Error: Could not reach the destination.";
}

// push the neighbors of the the current state into the priority queue or update their weight
void MatrixAStar::pushNeighborsOf(Point p) {
    auto neighbors = searchable_ -> getAllPossibleStates(p);
    auto p_amdc = path_matrix_.getCell(p);

    for (Point neighbor: neighbors) {
        bool addToOpen = false;

        // don't go back to your parent
        if (p_amdc.parent != neighbor) {
            AMDC& neighbor_amdc = path_matrix_.getCell(neighbor);
            auto weight = p_amdc.weight + searchable_-> getCost(neighbor);

            if (open_map_.count(neighbor.toString())) {
                if (neighbor_amdc.weight <= weight) {
                    continue;
                }
            } else if (close_.count(neighbor.toString())) {
                if (neighbor_amdc.weight <= weight) {
                    continue;
                }
                close_.erase(neighbor.toString());
                addToOpen = true;

            } else {
                addToOpen = true;
            }

            if (addToOpen) {
                open_.push_front(&neighbor_amdc);
                open_map_[neighbor.toString()] = open_.begin();
                open_.sort();
            }

            neighbor_amdc.weight = weight;
            neighbor_amdc.weightH = weight + distance(neighbor, searchable_->getGoalState());
            neighbor_amdc.parent = p;

        }
    }
}

unsigned int MatrixAStar::distance(Point p1, Point p2) {
    auto dist = abs((double) p1.getX() - p2.getX()) + abs((double) p1.getY() - p2.getY());
    return (unsigned int) dist;
}

/**
 * initialize the path matrix
 * @param searchable
 * @return
 */
void MatrixAStar::initPathMatrix() {
    for (int i = 0; i < searchable_ -> getSize().first; ++i) {
        vector<AMDC> row;
        path_matrix_.addRow(row);

        for (int j = 0; j < searchable_ -> getSize().second; ++j) {
            auto cell = AMDC();
            cell.myself = Point(i, j);
            path_matrix_[i].push_back(cell);
        }
    }
}