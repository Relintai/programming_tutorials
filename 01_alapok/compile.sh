
if [ ! -d "obj" ]; then
    mkdir obj
fi

if [ ! -d "bin" ]; then
    mkdir bin
fi

g++ -Wall -g -Iinclude -c main.cpp -o obj/main.o
g++ -Wall -g -Iinclude -c vector2.cpp -o obj/vector2.o
g++ -Wall -g -Iinclude -c vector3.cpp -o obj/vector3.o
g++ -Wall -g -Iinclude -c rect2.cpp -o obj/rect2.o
g++ -o bin/program obj/main.o obj/vector2.o obj/vector3.o obj/rect2.o 

