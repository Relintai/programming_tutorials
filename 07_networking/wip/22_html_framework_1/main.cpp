#include "core/http_server.h"



int main() {

    HTTPServer *server = new HTTPServer();

    server->port = 8080;
    server->initialize();
    server->main_loop();

    delete server;

    return 0;
}



