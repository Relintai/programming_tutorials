
cd libs/SDL2-2.0.12-src

rm -Rf build
mkdir build

cd ..
cd ..

export ANDROID_HOME=/home/relintai/SDKs/Android/SDK

./libs/SDL2-2.0.12-src/build-scripts/androidbuild.sh net.tapp.sdl  ./main.cpp

cd libs/SDL2-2.0.12-src/build/net.tapp.sdl

./gradlew installDebug