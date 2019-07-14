#!/bin/bash
# declare STRING variable
echo "Creating native make..."
if [ ! -d "build" ]; then
    mkdir build
fi

cd build

cmake -G "Unix Makefiles" ..
echo "Running native make"
make
echo "Running make test"
make test
#echo "Running tests"
#../bin/HttpClientTests
echo "Running CppLint"
echo "Inactivated cpp lint check"
#python cpplint/cpplint.py ../source/*.*