#download the vc sdl dev lib
#unzip
#move the lib to correct folder
#move headers / add to I
#add to include path


g++  main.cpp  -o ./bin/game.exe -Ilibs/SDL2-mingw/include \
    -Llibs/SDL2-mingw/lib \
    -lSDL2 -lSDL2main