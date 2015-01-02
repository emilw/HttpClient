#!/bin/bash
# declare STRING variable
echo "Creating native make..."
cmake -G "Unix Makefiles" ..
echo "Running native make"
make
echo "Running CppLint"
python cpplint/cpplint.py ../source/*.*
