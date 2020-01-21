//
// Created by yehonatan on 21/01/2020.
//

#ifndef SERVER_MY_PARALLEL_SERVER_H_
#define SERVER_MY_PARALLEL_SERVER_H_

#include "../client_handler/client_handler.h"
#include "iostream"
#include "sys/socket.h"
#include "server.h"
#include "../client_handler/client_handler.h"
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "chrono"
#include <string>
#include <list>
#define TIME_OUT 10
#define MAX_CLIENTS 10

using namespace std;

class MyParallelServer : public Server {
 public:
  void open(int, ClientHandler*);
  void close();
 private:
  void run(int &, ClientHandler* &);
  void acceptClients(int, sockaddr_in&, ClientHandler*);
  void runOneClient(ClientHandler*, int);
  bool keep_running_;
  list<thread> thread_list_;
};

#endif //SERVER_MY_PARALLEL_SERVER_H_
