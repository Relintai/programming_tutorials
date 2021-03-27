
if [ ! -d "obj" ]; then
    mkdir obj
fi

if [ ! -d "bin" ]; then
    mkdir bin
fi

#-Iinclude

g++ -Wall -g -c math.cpp -o obj/math.o
g++ -Wall -g -c main.cpp -o obj/main.o
g++ -o bin/program obj/math.o obj/main.o

