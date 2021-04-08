

#clang++ main.cpp -Wall -o3 -o ./bin/game -Ilibs/SDL2-linux/include -Llibs/SDL2-linux/lib -lSDL2 -lSDL2main

#g++ main.cpp -Wall -o3 -o ./bin/game -Ilibs/SDL2-linux/include -Llibs/SDL2-linux/lib -lSDL2 -lSDL2main

g++ main.cpp shader.cpp material.cpp mesh.cpp mesh_instance.cpp mesh_utils.cpp texture.cpp camera.cpp -g -Wall -o3 -o ./bin/game $(pkg-config --cflags --libs sdl2 glew)