#!/bin/sh

mkdir -p build
cd build
export LLVM_DIR=/data/haehcho/llvm/qc-80/build/llvm
cmake ..
make -j 4

