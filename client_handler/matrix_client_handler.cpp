//
// Created by rony on 19/01/2020.
//

#include "matrix_client_handler.h"

void MatrixClientHandler::handleClient(int & client_socket) {
    string solution, message;
    list<string> string_list;
    char buffer[BUFFER_SIZE] = {0};
    int val;

    while (keep_running_) {
        val = read(client_socket, buffer, 1024);
        message = Stringer::lineFromCharArray(buffer);

        if (message.size() >= 5) {
            string_list.push_back(message);
        } else if (!strcmp(message.c_str(), "end")) {
            keep_running_ = false;
        }
    }

    //make matrix from list
    //check if problem is in cache manager
    //if not, solve and add to cache
    //return to client the solution
}