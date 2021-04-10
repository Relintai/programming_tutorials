
rem mingw:
rem scoop install gcc

if not exist ./libs/sqlite/sqlite3.o (
    gcc -o3 -g ./libs/sqlite/sqlite3.c -o ./libs/sqlite/sqlite3.o -c -lpthread
)

g++ -o3 -g main.cpp ./core/http_server.cpp ./core/request.cpp ./core/application.cpp message_board.cpp ./libs/sqlite/sqlite3.o -o ./bin/server.exe -Ilibs -lpthread -lWsock32 -lWs2_32 -std=c++14

