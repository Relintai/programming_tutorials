
rem source ~/SDKs/emsdk/emsdk_env.sh


em++ main.cpp shader.cpp material.cpp mesh.cpp mesh_instance.cpp mesh_utils.cpp texture.cpp camera.cpp application.cpp scene.cpp game_scene.cpp object_2d.cpp tile_map.cpp ^
     --embed-file download.bmp -o bin/game_js.html -s USE_SDL=2

