rem -g  -> debug symbols
rem -o[0-3] -> optimization
rem -Wall -> all warning

g++ main.cpp shader.cpp ./libs/glad/src/glad.c -Wall -o3 -o ./bin/game.exe -Ilibs/SDL2-mingw/include -Llibs/SDL2-mingw/lib/x64 -Ilibs/glad/include -lSDL2 -lSDL2main -lOpengl32 