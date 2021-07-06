@echo off

if not defined DevEnvDir (
	call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
)

#debug: /Zi (== -g)

cl main.cpp /Febin/game-vc.exe ^
	/Ilibs\SDL2-VC\include ^
	/link /LIBPATH:libs\SDL2-VC\lib SDL2.lib SDL2main.lib ^
	/SUBSYSTEM:CONSOLE