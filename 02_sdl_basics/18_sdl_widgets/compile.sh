
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

g++ -Wall -g -I. -c core/math.cpp -o obj/math.o
g++ -Wall -g $(sdl2-config --cflags) -I. -c core/rect2.cpp -o obj/rect2.o
g++ -Wall -g $(sdl2-config --cflags) -I. -c core/color.cpp -o obj/color.o
g++ -Wall -g $(sdl2-config --cflags) -I. -c core/vector2.cpp -o obj/vector2.o
g++ -Wall -g $(sdl2-config --cflags) -I. -c core/vector3.cpp -o obj/vector3.o
g++ -Wall -g -I. -c core/string.cpp -o obj/string.o

g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/renderer.cpp -o obj/renderer.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/image.cpp -o obj/image.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/texture.cpp -o obj/texture.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/sprite.cpp -o obj/sprite.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/camera.cpp -o obj/camera.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/text_image.cpp -o obj/text_image.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/text_sprite.cpp -o obj/text_sprite.o 

g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/true_type_font.cpp -o obj/true_type_font.o

g++ -Wall -g $(sdl2-config --cflags) -I. -c widgets/widget.cpp -o obj/widget.o 

g++ -Wall -g $(sdl2-config --cflags) -I. -c renderer/button.cpp -o obj/button.o 

g++ -Wall -g $(sdl2-config --cflags) -I. -c scene.cpp -o obj/scene.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c application.cpp -o obj/application.o 
g++ -Wall -g $(sdl2-config --cflags) -I. -c main_scene.cpp -o obj/main_scene.o 

g++ -Wall -g $(sdl2-config --cflags) -I. -c main.cpp -o obj/main.o

g++ -o bin/program obj/math.o obj/rect2.o obj/color.o obj/vector2.o obj/vector3.o obj/string.o obj/renderer.o obj/image.o obj/texture.o obj/sprite.o obj/camera.o obj/text_image.o obj/text_sprite.o  obj/true_type_font.o obj/widget.o obj/button.o obj/scene.o obj/application.o obj/main_scene.o   obj/main.o $(sdl2-config --libs) -lSDL2_ttf 

