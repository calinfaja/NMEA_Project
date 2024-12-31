#!/bin/bash

# Create and enter build directory
rm -rf build
mkdir -p build
cd build

# Configure CMake with good defaults
cmake .. \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DCMAKE_CXX_COMPILER=g++ \
    -DCMAKE_C_COMPILER=gcc \
    -DCMAKE_CXX_FLAGS="-Wall -Wextra -Wpedantic -fdiagnostics-color=always"

# Build the project
cmake --build . -- -j$(nproc)

# Return to project root
cd ..

# Create symbolic link for compile_commands.json
ln -sf build/compile_commands.json .
