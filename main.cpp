//
// Created by rony on 13/01/2020.
//

#include "iostream"
#include "string"
#include <list>
#include "global_vars.h"
#include "searchables/matrix_searchable.h"
#include "server/my_parallel_server.h"
#include "client_handler/my_client_handler.h"

#define PORT 5600

using namespace server_side;
using namespace std;

// set global vars
FileCacheManager<Searchable<Point>*, string> file_cache_manager = FileCacheManager<Searchable<Point>*, string>();

int main(int argc, char *argv[]) {
    MyParallelServer sersev;
    int port = PORT;

    //port parameter was entered
    if(argc >= 2) {
        port = stoi(argv[1]);
    }

    try {
        sersev.open(port, new MyClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }

    return 0;
}
