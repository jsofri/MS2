//
// Created by yehonatan on 09/01/2020.
//

#include "my_test_client_handler.h"


void MyTestClientHandler::handleClient(int& client_socket) {

    //reading from client
    string solution, message;
    char buffer[BUFFER_SIZE] = {0};
    int val;

    do {
        val = read(client_socket, buffer, 1024);

        if (val == -1) {
            throw "couldn't accept message from client";
        }

        message = Stringer::stringFromCharArray(buffer);

        StringWrapper string_wrapper(message);

        try {
            solution = file_cache_manager_.get(string_wrapper);

        } catch (const char * e) {
            solution = solver_.solve(string_wrapper);
            file_cache_manager_.insert(string_wrapper, solution);
        }

        solution += '\n';
        val = send(client_socket, solution.c_str(), solution.length(), 0);

        if (val == -1) {
            throw "couldn't send message to client";
        }

    } while (message != "end");
}
