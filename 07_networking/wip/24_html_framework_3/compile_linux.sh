
if [ ! -f ./libs/sqlite/sqlite3.o ]; then
    gcc -o3 -g ./libs/sqlite/sqlite3.c -o ./libs/sqlite/sqlite3.o -c -lpthread -ldl
fi

g++ -o3 -g main.cpp ./core/http_server.cpp ./core/request.cpp ./core/application.cpp message_board.cpp ./libs/sqlite/sqlite3.o -o ./bin/server -Ilibs -lpthread -ldl -std=c++11

