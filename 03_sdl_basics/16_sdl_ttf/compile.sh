
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

g++ -Wall -g -c math.cpp -o obj/math.o
g++ -Wall -g $(sdl2-config --cflags) -c rect2.cpp -o obj/rect2.o
g++ -Wall -g $(sdl2-config --cflags) -c color.cpp -o obj/color.o
g++ -Wall -g -c string.cpp -o obj/string.o

g++ -Wall -g $(sdl2-config --cflags) -c renderer.cpp -o obj/renderer.o 
g++ -Wall -g $(sdl2-config --cflags) -c image.cpp -o obj/image.o 
g++ -Wall -g $(sdl2-config --cflags) -c texture.cpp -o obj/texture.o 
g++ -Wall -g $(sdl2-config --cflags) -c sprite.cpp -o obj/sprite.o 
g++ -Wall -g $(sdl2-config --cflags) -c camera.cpp -o obj/camera.o 

g++ -Wall -g $(sdl2-config --cflags) -c font.cpp -o obj/font.o 

g++ -Wall -g $(sdl2-config --cflags) -c button.cpp -o obj/button.o 

g++ -Wall -g $(sdl2-config --cflags) -c scene.cpp -o obj/scene.o 
g++ -Wall -g $(sdl2-config --cflags) -c application.cpp -o obj/application.o 
g++ -Wall -g $(sdl2-config --cflags) -c main_scene.cpp -o obj/main_scene.o 

g++ -Wall -g $(sdl2-config --cflags) -c main.cpp -o obj/main.o

g++ -o bin/program obj/math.o obj/rect2.o obj/color.o obj/string.o obj/renderer.o obj/image.o obj/texture.o obj/sprite.o obj/camera.o obj/font.o obj/button.o obj/scene.o obj/application.o obj/main_scene.o   obj/main.o $(sdl2-config --libs) -lSDL2_ttf 

