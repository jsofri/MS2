//
// Created by rony on 13/01/2020.
//

#include "global_vars.h"
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
#include "searchers/searcher.h"
#include <list>
#include "server/my_parallel_server.h"
#include "client_handler/my_client_handler.h"
#include "util/print_to_file.h"

#define PORT 5402
#define MIN_RANK 10
#define MAX_RANK 50
#define REQUIRED_MATRICES 10
#define JUMP 4
#define MATRIX_DIRECTORY "matrices_output/"
#define SEARCHER_PAIR std::pair<Searcher<Point, string>*, string>
#define GENERATE_RANDOM false

using namespace server_side;
using namespace std;

// set global vars
FileCacheManager<Searchable<Point>*, string> file_cache_manager = FileCacheManager<Searchable<Point>*, string>();


bool endNotEntered(list<string> lines_list_) {
  string last_line = lines_list_.back();
  bool endIn = false;

  if (last_line.size() < 5) {
    endIn = (last_line.size() == strspn(last_line.c_str(), "end\n"));
  }

  return endIn;
}

void doo() {
  list <string> lines_list_;
  char buffer[BUFFER_SIZE];
  string str;

  do {
    cin >> buffer;

    list<string> tmp_list = Stringer::stringListFromCharArray(buffer);

    //add tmp_list to lines_list_
    lines_list_.insert(lines_list_.end(), tmp_list.begin(), tmp_list.end());

  } while (endNotEntered(lines_list_));
}

void foo() {

    string path_results = MATRIX_DIRECTORY;
    path_results += "results/";
    string path_matrices = MATRIX_DIRECTORY;
    path_matrices += "matrices/";


    for (int i = MIN_RANK; i <= MAX_RANK; i += JUMP) {
        bool matrixWritten = false;
        string matrix_file_name = "RANK_" + to_string(i);

        std::list<SEARCHER_PAIR> searchers;
        searchers.push_back(SEARCHER_PAIR(new MatrixBFS(), "BFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixDFS(), "DFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixBestFS(), "BestFS"));
        searchers.push_back(SEARCHER_PAIR(new MatrixAStar(), "AStar"));

        Matrix<int> matrix;
        if (GENERATE_RANDOM) {
            matrix = MatrixBuilder::randomMatrix(i);
        } else {
            matrix = MatrixBuilder::fromFile(path_matrices + matrix_file_name + ".matrix");
        }

        cout << "Rank: " << to_string(i) << endl;

        for (auto pair : searchers) {
            auto searcher = pair.first;
            auto classname = pair.second;

            // print matrix to file
            if (GENERATE_RANDOM && !matrixWritten) {
                MatrixBuilder::writeToFile(matrix, path_matrices + matrix_file_name + ".matrix");
                matrixWritten = true;
            }

            // search and print result to file
            MatrixSearchable matrix_searchable(matrix);
            string result = searcher->search(matrix_searchable);
            auto vertices = searcher -> getTraversedVerixes();
            cout << "\t" <<  classname << ": " << to_string(vertices) << endl;

            string path = path_results + classname + to_string(i) + ".result";
            PrintToFile::write(result, path);
        }
    }
}

void hoo(){
  MatrixBuilder matrix_builder;
  Matrix<int> matrix;
  list<string> list;

  list.push_back("5,6,-1,2,1");
  list.push_back("0\n3,2,4,3,6\n1");
  list.push_back(",-1,9,3,3\n4");
  list.push_back(",5,6,7,8\n9,10,-1,2,3\n0");
  list.push_back(",0\n4,4\nend\n");

  matrix_builder.buildNXNMatrix(Stringer::listOfLines(list));

  matrix = matrix_builder.getMatrix();

  cout << matrix.getSize().second << endl;
}


/**
 * Testing part 2
 */
int main() {
    // alert so we won't forget
    if (PORT != 5600) {
        cerr << "Attention: Port is not 5600" << endl;
    }

    MyParallelServer sersev;
    try {
        sersev.open(PORT, new MyClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }

    return 0;
}