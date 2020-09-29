#!/usr/bin/env bash

set -e

# Configure the build system (cmake) right from the start.
rm -rf build
mkdir build
cd build
conan install ../src -s build_type=Debug
cmake ../src -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
