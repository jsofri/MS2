//
// Created by yehonatan on 09/01/2020.
//


#include "my_test_client_handler.h"

using namespace server_side;

void MyTestClientHandler::handleClient(int& client_socket) {

    //reading from client
    int n;
    char buffer[1024] = {0};
    int valread = read( client_socket , buffer, 1024);
    std::cout<<buffer<<std::endl;

    n = this -> reverseString(buffer);

    send(client_socket , buffer , n , 0 );
    //message sent
}

int MyTestClientHandler::reverseString(char * str) {
    int length = strlen(str);
    char tmp;

    for (int i = 0; i < length / 2; i++) {
        tmp = str[i];
        str[i] = str[length - 1 - i];
        str[length -1 - i] = tmp;
    }

    return length;
}