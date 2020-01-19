//
// Created by rony on 17/01/2020.
//

#include <cmath>
#include "matrix_astar.h"
#include "matrix_solution_analyst.h"

string MatrixAStar::search(Searchable<Point>& searchable) {
    MatrixSolutionAnalyst msa;
    string solution;
    searchable_ = &searchable;

    // initialize the path matrix
    initPathMatrix();

    // push the neighbors of the initial state into the priority queue
    auto initial = searchable_ -> getInitialState();
    path_matrix_.getCell(initial).weight = searchable_ -> getCost(initial);
    pushNeighborsOf(initial);

    // do the recursion
    try {
        runAStar();
    } catch (const char * exception) {
        cerr << exception << endl;
    }

    // return solution
    auto end = searchable_ -> getGoalState();
    solution = msa.getSolution(path_matrix_, initial, end, searchable);
    return solution;
}

void MatrixAStar::runAStar() {
    while (!queue_.empty()) {
        auto top = queue_.front().second.myself;
        auto topIter = queue_.begin();

        // check if goal has been reached
        if (searchable_->isGoalState(top)) {
            return;
        }

        // remove top from priority queue and map
        queue_.erase(topIter);
        map_.erase(top.toString());

        //cout << "erased top: " << top.toString() << endl;

        // push neighbors
        pushNeighborsOf(top);
    }
    throw "Error: Could not reach the destination.";
}

unsigned int MatrixAStar::distance(Point p1, Point p2) {
    auto dist = abs((double) p1.getX() - p2.getX()) + abs((double) p1.getY() - p2.getY());
    return (unsigned int) dist;
}

void MatrixAStar::pushNeighborsOf(Point p) {
    auto neighbors = searchable_ -> getAllPossibleStates(p);
    auto p_amdc = path_matrix_.getCell(p);

    for (Point neighbor: neighbors) {
        //cout << "neighbor: " << neighbor.toString() << endl;
        // don't go back to your parent
        if (p_amdc.parent != neighbor){
            AMDC& neighbor_amdc = path_matrix_.getCell(neighbor);
            // don't change weight of neighbor if it has smaller weight
            if (neighbor_amdc.weight >= p_amdc.weight + searchable_-> getCost(neighbor)) {
                neighbor_amdc.parent = p;
                neighbor_amdc.weight = p_amdc.weight + searchable_-> getCost(neighbor);

                //cout << "     updated: parent:" << p.toString() << " weight: " << neighbor_amdc.weight << endl;

                // push neighbor if he does not already exist in queue
                if (map_.count(neighbor.toString()) == 0) {
                    double weight_with_phys_dist = neighbor_amdc.weight + distance(neighbor, searchable_->getGoalState());
                    auto pair = std::pair<double, AMDC>(weight_with_phys_dist, neighbor_amdc);
                    queue_.PriorityQ::push(pair);
                    map_[neighbor.toString()] = true;

                    //cout << "     and added: physic:" << weight_with_phys_dist << endl;
                }
            }
        }
    }
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