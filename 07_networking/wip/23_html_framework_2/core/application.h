#ifndef APPLICATION_H
#define APPLICATION_H

#include <functional>
#include <map>
#include <string>
#include <vector>

class Request;

class Application {
public:
    static void handle_request(Request *request);
    static void send_error(int error_code, Request* request);
    static void send_file(const std::string &path, Request *request);

    static void default_fallback_error_handler(int error_code, Request *request);
    static void default_404_error_handler(int error_code, Request *request);

    virtual void setup_routes();
    virtual void setup_middleware();

    static void default_routing_middleware(Request *request);

    static void default_index_func(Request *request);

    Application();
    virtual ~Application();

    static std::function<void(Request*)> index_func;
    static std::map<std::string, std::function<void(Request*)> > main_route_map;
    static std::map<int, std::function<void(int, Request*)> > error_handler_map;
    static std::function<void(int, Request*)> default_error_handler_func;

    static std::vector<std::function<void(Request*)> > middlewares;
};


#endif
