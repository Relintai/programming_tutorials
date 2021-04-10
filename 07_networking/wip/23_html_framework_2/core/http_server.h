#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <iostream>
#include <string>

#include <brynet/base/AppStatus.hpp>
#include <brynet/net/http/HttpFormat.hpp>
#include <brynet/net/http/HttpService.hpp>
#include <brynet/net/http/WebSocketFormat.hpp>
#include <brynet/net/wrapper/HttpServiceBuilder.hpp>
#include <brynet/net/wrapper/ServiceBuilder.hpp>

using namespace brynet;
using namespace brynet::net;
using namespace brynet::net::http;

class Request;

class HTTPServer {
public:
    int port;
    int threads;

    std::shared_ptr<TcpService> service;
    wrapper::HttpListenerBuilder *listener_builder;

    static void example_http_callback_handler(Request *request);

    static void http_enter_callback_default(const HTTPParser &http_parser, const HttpSession::Ptr &session);

    virtual void configure();
    virtual void initialize();

    void main_loop();

    HTTPServer();
    virtual ~HTTPServer();
};

#endif