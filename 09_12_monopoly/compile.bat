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

%GPP% -Wall %VER% -c string.cpp -o obj/string.o
%GPP% -Wall %VER% -c math.cpp -o obj/math.o

%GPP% -Wall %VER% -c tile.cpp -o obj/tile.o
%GPP% -Wall %VER% -c player.cpp -o obj/player.o

%GPP% -Wall %VER% -c player_loader.cpp -o obj/player_loader.o
%GPP% -Wall %VER% -c tile_loader.cpp -o obj/tile_loader.o

%GPP% -Wall %VER% -c board.cpp -o obj/board.o

%GPP% -Wall %VER% -c main.cpp -o obj/main.o

%GPP% -o bin/program.exe obj/math.o obj/main.o

%GPP% -o bin/program obj/string.o obj/math.o obj/tile.o obj/tile_loader.o obj/player.o obj/player_loader.o obj/board.o obj/main.o
