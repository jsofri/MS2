//
// Created by rony on 13/01/2020.
//

#include "server/my_serial_server.h"
#include "client_handler/my_test_client_handler.h"
#include "objects/matrix.h"
#include "builders/matrix_builder.h"
#include "iostream"
#include "string"
#include "searchables/matrix_searchable.h"
#include "searchers/matrix_dfs.h"
#include "searchers/matrix_bfs.h"
#include "searchers/matrix_astar.h"
#include "searchers/matrix_best_fs.h"
#include <util/matrix_generator.h>
#include <searchers/searcher.h>
#include <list>
#include <util/print_to_file.h>
#include <util/matrix_int_to_file.h>

#define PORT 5402
#define MIN_RANK 10
#define MAX_RANK 50
#define REQUIRED_MATRICES 10
#define JUMP 4
#define MATRIX_DIRECTORY "matrices_output/"
#define SEARCHER_PAIR std::pair<Searcher<Point, string>*, string>
#define GENERATE_RANDOM false

using namespace server_side;

void foo() {

    string path_results = MATRIX_DIRECTORY;
    path_results += "results/";
    string path_matrices = MATRIX_DIRECTORY;
    path_matrices += "matrices/";


    for (int i = MIN_RANK; i <= MAX_RANK; i += JUMP) {
        string file_name = "BFS" + to_string(i);

        std::list<SEARCHER_PAIR> searchers;
        searchers.push_back(SEARCHER_PAIR(new MatrixBFS(), "BFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixDFS(), "DFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixBestFS(), "BestFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixAStar(), "AStar"));

        Matrix<int> matrix;
        if (GENERATE_RANDOM) {
            matrix = MatrixGenerator::randomMatrix(i);
        } else {
            matrix = MatrixGenerator::fromFile(path_matrices + file_name + ".matrix");
        }

        MatrixSearchable matrix_searchable(&matrix);
        cout << "Rank: " << to_string(i) << endl;

        for (auto pair : searchers) {
            auto searcher = pair.first;
            auto classname = pair.second;

            // print matrix to file
            if (!GENERATE_RANDOM) {
                MatrixIntToFile::write(matrix, path_matrices + file_name + ".matrix");
            }

            // search and print result to file
            string result = searcher->search(matrix_searchable);
            auto vertices = searcher -> getTraversedVerixes();
            cout << "\t" <<  classname << ": " << to_string(vertices) << endl;

            PrintToFile::write(result, path_results + file_name + ".result");
        }
    }
}

int main() {
    foo();
    return 0;
}

/**
 * Testing part 2
 */
int mainPart2() {
    MySerialServer sersev;
    try {
        sersev.open(PORT, new MyTestClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }

    return 0;
}