
if [ ! -d "obj" ]; then
    mkdir obj
fi

if [ ! -d "bin" ]; then
    mkdir bin
fi

#-Iinclude

#g++ -Wall -g -c vector2.cpp -o obj/vector2.o
#g++ -Wall -g -c vector3.cpp -o obj/vector3.o
#g++ -Wall -g -c int_vector.cpp -o obj/int_vector.o
#g++ -Wall -g -c string.cpp -o obj/string.o

g++ -Wall -g -c math.cpp -o obj/math.o
g++ -Wall -g -c rect2.cpp -o obj/rect2.o
g++ -Wall -g -c color.cpp -o obj/color.o

g++ -Wall -g $(sdl2-config --cflags) -c renderer.cpp -o obj/renderer.o 
g++ -Wall -g $(sdl2-config --cflags) -c image.cpp -o obj/image.o 
g++ -Wall -g $(sdl2-config --cflags) -c texture.cpp -o obj/texture.o 
g++ -Wall -g $(sdl2-config --cflags) -c texture_editor.cpp -o obj/texture_editor.o 

g++ -Wall -g $(sdl2-config --cflags) -c main.cpp -o obj/main.o

g++ -o bin/program obj/math.o obj/rect2.o obj/color.o obj/renderer.o obj/image.o obj/texture.o obj/texture_editor.o obj/main.o $(sdl2-config --libs) 

