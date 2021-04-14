@echo off

if not defined DevEnvDir (
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
)

rem debug: /Zi (== -g)

cl main.cpp libs\glad\src\glad.c /Febin/game-vc.exe ^
	/Ilibs\SDL2-VC\include ^
	/Ilibs\glad\include ^
	/link /LIBPATH:libs\SDL2-VC\lib SDL2.lib SDL2main.lib opengl32.lib ^
	/SUBSYSTEM:CONSOLE