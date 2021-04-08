#include "application.h"

#include "request.h"
#include "../message_board.h"

void Application::handle_request(Request *request) {
    request->middleware_stack = &middlewares;

    request->next_stage();
}

void Application::send_error(int error_code, Request *request) {
    std::function<void(int, Request*)> func = error_handler_map[error_code];

    if (!func) {
        default_error_handler_func(error_code, request);
        return;
    }

    func(error_code, request);
}

void Application::send_file(const std::string &path, Request *request) {
    //később
}

void Application::default_fallback_error_handler(int error_code, Request *request) {
    request->response->setBody("<html><body>internal server error!</body></html>");
    request->send();
}

void Application::default_404_error_handler(int error_code, Request *request) {
    request->response->setBody("<html><body>404</body></html>");
    request->send();
}

void Application::setup_routes() {
    default_error_handler_func = Application::default_fallback_error_handler;

    error_handler_map[404] = Application::default_404_error_handler;

    index_func = default_index_func;
    main_route_map["aaa"] = default_index_func;
    main_route_map["msgb"] = message_board_func;
}

void Application::setup_middleware() {
    middlewares.push_back(Application::default_routing_middleware);
}

void Application::default_routing_middleware(Request *request) {
    std::string path = request->http_parser->getPath();

    std::function<void(Request*)> func;

    if (path == "/") {
        func = index_func;
    } else {
        std::string main_route = "";

        uint32_t endpos = 1;
        for (; endpos < path.size(); ++endpos) {
            if (path[endpos] == '/') {
                break;
            }
        }

        main_route = path.substr(1, endpos - 1);

        func = main_route_map[main_route];
    }

    if (!func) {
        send_error(404, request);
        return;
    }

    request->handler_func = func;
    request->next_stage();
}

void Application::default_index_func(Request *request) {
	request->response->setBody("<html><body><p>HELLO WORLD!</p></body></html>");
	request->send();
}

void Application::message_board_func(Request *request) {
	MessageBoard::handle_request(request);
}

Application::Application() {

}

Application::~Application() {
    main_route_map.clear();
    error_handler_map.clear();
    middlewares.clear();
}

std::function<void(Request *)> Application::index_func;
std::map<std::string, std::function<void(Request *)> > Application::main_route_map;
std::map<int, std::function<void(int, Request *)> > Application::error_handler_map;
std::function<void(int, Request *)> Application::default_error_handler_func;

std::vector<std::function<void(Request *)> > Application::middlewares;
