rm -rd build/
mkdir build && cd build
cmake ..
make all
./Ascent
cd ..