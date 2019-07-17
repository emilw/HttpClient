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
ctest && \

echo "Running CppLint" && \
echo "Inactivated cpp lint check"

cd ..

if [ ! -d "bin" ]; then
    mkdir bin
fi

cp build/HttpClient bin/HttpClient

python build_stuff/cpplint/cpplint.py source/*.*