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


%GPP% -Wall %VER% -c math.cpp -o obj/math.o
%GPP% -Wall %VER% -c vector2.cpp -o obj/vector2.o
%GPP% -Wall %VER% -c vector3.cpp -o obj/vector3.o
%GPP% -Wall %VER% -c rect2.cpp -o obj/rect2.o
%GPP% -Wall %VER% -c main.cpp -o obj/main.o

%GPP% -o bin/program.exe obj/math.o obj/main.o
