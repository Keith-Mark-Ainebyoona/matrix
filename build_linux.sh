#!/usr/bin/env bash

printf "\x1b[1;7m[+] Building done with an out-of-source build...\x1b[m\n"
mkdir build
cd build
cmake ..
cmake --build . # invoke make
