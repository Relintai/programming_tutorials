
if [ ! -d "obj" ]; then
    mkdir obj
fi

if [ ! -d "bin" ]; then
    mkdir bin
fi

#-Iinclude

g++ -Wall -g -c math.cpp -o obj/math.o
g++ -Wall -g -c vector2.cpp -o obj/vector2.o
g++ -Wall -g -c vector3.cpp -o obj/vector3.o
g++ -Wall -g -c rect2.cpp -o obj/rect2.o
g++ -Wall -g -c main.cpp -o obj/main.o
g++ -o bin/program obj/math.o obj/main.o

