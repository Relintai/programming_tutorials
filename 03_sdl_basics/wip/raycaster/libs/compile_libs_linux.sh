
dir=$(pwd)

rm -Rf SDL2-linux
mkdir SDL2-linux

set CC=$dir/SDL2-2.0.12-src/build-scripts/gcc-fat.sh

cd SDL2-2.0.12-src
rm -Rf build
mkdir build
cd build

../configure -prefix=$dir/SDL2-linux

make -j4
make install
