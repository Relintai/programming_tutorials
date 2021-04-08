#installalt sdl el
#g++ main.cpp -o game $(pkg-config --cflags --libs sdl2)

#switchek
#-g
#-Wall
#-o0 - -o3


#g++ main.cpp -o3 -o ./bin/game $(pkg-config --cflags --libs sdl2)

#clang++ main.cpp -o3 -o ./bin/game $(pkg-config --cflags --libs sdl2)

g++ main.cpp -o3 -o ./bin/game \
    -Ilibs/SDL2-linux/include \
    -Ilibs/SDL2-linux/lib \
    -lSDL2 