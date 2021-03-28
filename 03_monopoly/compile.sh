
if [ ! -d "obj" ]; then
    mkdir obj
fi

if [ ! -d "bin" ]; then
    mkdir bin
fi

#-Iinclude

g++ -Wall -g -c string.cpp -o obj/string.o
g++ -Wall -g -c math.cpp -o obj/math.o

g++ -Wall -g -c tile.cpp -o obj/tile.o
g++ -Wall -g -c player.cpp -o obj/player.o

g++ -Wall -g -c player_loader.cpp -o obj/player_loader.o
g++ -Wall -g -c tile_loader.cpp -o obj/tile_loader.o

g++ -Wall -g -c main.cpp -o obj/main.o
g++ -o bin/program obj/string.o obj/math.o obj/tile.o obj/tile_loader.o obj/player.o obj/player_loader.o obj/main.o

