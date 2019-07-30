#!/bin/sh

mkdir -p build
cd build
export LLVM_DIR=/data/haehcho/llvm/qc-60/install
cmake ..
make -j 4

