﻿#include <iostream>
#include <mutex>
#include <atomic>

#include <brynet/net/EventLoop.hpp>
#include <brynet/net/TcpService.hpp>
#include <brynet/net/wrapper/ServiceBuilder.hpp>
#include <brynet/base/AppStatus.hpp>

using namespace brynet;
using namespace brynet::net;

std::atomic_llong TotalRecvSize = ATOMIC_VAR_INIT(0);
std::atomic_llong total_client_num = ATOMIC_VAR_INIT(0);
std::atomic_llong total_packet_num = ATOMIC_VAR_INIT(0);

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: <listen port> <net work thread num>\n");
        exit(-1);
    }

    auto service = TcpService::Create();
    service->startWorkerThread(atoi(argv[2]));

    auto enterCallback = [](const TcpConnection::Ptr& session) {
        total_client_num++;

        session->setDataCallback([session](const char* buffer, size_t len) {
                session->send(buffer, len);
                TotalRecvSize += len;
                total_packet_num++;

                std::cout << "-------------------------------------  PACKET  -------------------------------------" << std::endl;
                std::cout << buffer << std::endl;
                std::cout << "------------------------------------------------------------------------------------" << std::endl << std::endl;

                return len;
            });

        session->setDisConnectCallback([](const TcpConnection::Ptr& session) {
                (void)session;
                total_client_num--;
            });
    };

    wrapper::ListenerBuilder listener;
    listener.configureService(service)
        .configureSocketOptions({
            [](TcpSocket& socket) {
                socket.setNodelay();
            }
        })
        .configureConnectionOptions({
            brynet::net::AddSocketOption::WithMaxRecvBufferSize(1024 * 1024),
            brynet::net::AddSocketOption::AddEnterCallback(enterCallback)
        })
        .configureListen([=](wrapper::BuildListenConfig config) {
            config.setAddr(false, "0.0.0.0", atoi(argv[1]));
        })
        .asyncRun();

    EventLoop mainLoop;
    while (true)
    {
        mainLoop.loop(1000);

        total_packet_num = 0;
        TotalRecvSize = 0;

        if (brynet::base::app_kbhit())
        {
            break;
        }
    }

    return 0;
}
