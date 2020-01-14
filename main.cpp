//
// Created by rony on 13/01/2020.
//

#include "my_serial_server.h"
#include "my_test_client_handler.h"
#define PORT 5402

using namespace server_side;

int main() {
    MySerialServer sersev;
    try {
        sersev.open(PORT, new MyTestClientHandler());
        sersev.close();
    } catch (const char* e) {
        cerr << e << endl;
    }
}