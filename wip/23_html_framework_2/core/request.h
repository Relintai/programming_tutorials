#ifndef REQUEST_H
#define REQUEST_H

#include <functional>
#include <vector>
#include <mutex>

#include <brynet/net/http/HttpService.hpp>
#include <brynet/net/http/HttpFormat.hpp>

using namespace brynet;
using namespace brynet::net;
using namespace brynet::net::http;

class Request {
public:
    const HTTPParser *http_parser;
    const HttpSession::Ptr *session;
    HttpResponse *response;
    
    uint32_t current_middleware_index;
    std::function<void(Request *)> handler_func;
    std::vector<std::function<void(Request *)> > *middleware_stack;

    //std::map<std::string, Object*> data;

    void next_stage();
    void send();
    void reset();

    Request();
    ~Request();
};

class RequestPool {
public:
    static Request* get_request();
    static void return_request(Request *request);

    RequestPool();
    ~RequestPool();

protected:
    static std::mutex _mutex;
    static std::vector<Request *> _requests;
};

#endif