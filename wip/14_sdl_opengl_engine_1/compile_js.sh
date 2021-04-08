
#source ~/SDKs/emsdk/emsdk_env.sh

#saját fodítás
#em++ main.cpp libs/SDL2-js/lib/libSDL2.a -o game.html \
#    -Ilibs/SDL2-js/include \
#    -Ilibs/SDL2-js/lib 

em++ main.cpp shader.cpp -o bin/game_js.html -s USE_SDL=2

