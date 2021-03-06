@echo off

if not exist "obj" (
    mkdir obj
)

if not exist "bin" (
    mkdir bin
)

rem debug
set VER=-g

if "%~1"=="r" (
    set VER=-o3
)

set GPP=g++

for %%X in (g++.exe) do (set FOUND=%%~$PATH:X)

if not defined FOUND (
    set GPP="C:\Program Files\CodeBlocks\MinGW\bin\g++"
)

set SDL2_CFLAGS=-I..\..\lib\SDL2\include\SDL2
set SDL2_LIBS=-L..\..\lib\SDL2\lib -lmingw32 -lSDL2main -lSDL2.dll -luser32 -lgdi32 -lwinmm -ldxguid
XCOPY ..\..\lib\SDL2\bin\*.dll bin /D /Y


%GPP% -Wall %VER% -c math.cpp -o obj/math.o
%GPP% -Wall %VER% %SDL2_CFLAGS% -c rect2.cpp -o obj/rect2.o
%GPP% -Wall %VER% -c color.cpp -o obj/color.o
%GPP% -Wall %VER% -c string.cpp -o obj/string.o

%GPP% -Wall %VER% %SDL2_CFLAGS% -c renderer.cpp -o obj/renderer.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c image.cpp -o obj/image.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c texture.cpp -o obj/texture.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c sprite.cpp -o obj/sprite.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c camera.cpp -o obj/camera.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c button.cpp -o obj/button.o 

%GPP% -Wall %VER% %SDL2_CFLAGS% -c scene.cpp -o obj/scene.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c application.cpp -o obj/application.o 
%GPP% -Wall %VER% %SDL2_CFLAGS% -c main_scene.cpp -o obj/main_scene.o 

%GPP% -Wall %VER% %SDL2_CFLAGS% -c main.cpp -o obj/main.o

%GPP% -o bin/program obj/math.o obj/rect2.o obj/color.o obj/string.o obj/renderer.o obj/image.o obj/texture.o obj/sprite.o obj/camera.o obj/button.o obj/scene.o obj/application.o obj/main_scene.o   obj/main.o %SDL2_LIBS%
