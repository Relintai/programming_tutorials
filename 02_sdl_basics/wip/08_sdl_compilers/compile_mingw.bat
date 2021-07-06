rem -g  -> debug symbols
rem -o[0-3] -> optimization
rem -Wall -> all warning

g++ main.cpp -Wall -o3 -o ./bin/game.exe -Ilibs/SDL2-mingw/include -Llibs/SDL2-mingw/lib/x64 -lSDL2 -lSDL2main