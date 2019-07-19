#!/bin/bash
# declare STRING variable
echo "Creating native make..."
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake -G "Unix Makefiles" .. && \

echo "Running native make" && \
make && \

echo "Running make test" && \
ctest --verbose && \

echo "Running CppLint" && \
python ../build_stuff/cpplint/cpplint.py ../source/*.*

if [ $? -eq 0 ]; then
    echo "Build and lint succeded"
else
    printf "\033[1;31mBuild or lint failed, no copy to the bin folder will be made\033[0m\n"
    exit 1
fi

cd ..

if [ ! -d "bin" ]; then
    mkdir bin
fi

echo "Copying the executable to the bin folder"
cp build/HttpClient bin/HttpClient

