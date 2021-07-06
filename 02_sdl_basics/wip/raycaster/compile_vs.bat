@echo off

rem /Zi debug info

if not defined DevEnvDir (
    call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
)

cl /Zi /EHsc ^
main.cpp /Fegame.exe ^
/Ilibs\SDL2-2.0.12-src\include\ ^
/link /LIBPATH:libs\x64\Release\ ^
SDL2.lib SDL2main.lib  ^
/SUBSYSTEM:CONSOLE
