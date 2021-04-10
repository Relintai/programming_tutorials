
dir=$(pwd)

rm -Rf SDL2-js
mkdir SDL2-js

cd SDL2-2.0.12-src
rm -Rf build
mkdir build
cd build

emconfigure ../configure -prefix=$dir/SDL2-js --host=asmjs-unknown-emscripten --disable-assembly --disable-threads --disable-cpuinfo CFLAGS="-O2"

emmake make -j4
make install
