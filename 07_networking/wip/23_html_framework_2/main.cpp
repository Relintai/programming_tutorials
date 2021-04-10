#include "core/http_server.h"

#include "core/application.h"

int main() {

    HTTPServer *server = new HTTPServer();
    Application *app = new Application();
    app->setup_routes();
    app->setup_middleware();

    server->port = 8080;
    server->initialize();
    server->main_loop();

    delete server;
    delete app;

    return 0;
}



