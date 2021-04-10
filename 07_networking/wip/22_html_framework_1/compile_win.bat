
rem mingw:
rem scoop install gcc

g++ -o3 -g main.cpp ./core/http_server.cpp -o ./bin/server.exe -Ilibs -lpthread -lWsock32 -lWs2_32 -std=c++14

