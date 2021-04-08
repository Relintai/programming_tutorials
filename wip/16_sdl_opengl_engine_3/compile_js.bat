
rem source ~/SDKs/emsdk/emsdk_env.sh


em++ main.cpp shader.cpp material.cpp mesh.cpp mesh_instance.cpp mesh_utils.cpp texture.cpp -o bin/game_js.html -s USE_SDL=2

