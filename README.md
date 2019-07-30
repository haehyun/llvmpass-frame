### Build LLVM v6.0.0
```
wget http://releases.llvm.org/6.0.0/llvm-6.0.0.src.tar.xz
wget http://releases.llvm.org/6.0.0/cfe-6.0.0.src.tar.xz

mv cfe-6.0.0.src llvm-6.0.0.src/tools/clang
cd llvm-6.0.0.src
mkdir build
cd build
cmake ${PATH_TO_LLVM_SOURCE_ROOT}

cmake --build . -- -j 16
cmake --build . --target install
```

### How to build & clean
```
./build.sh (after changing the path of LLVM_DIR in the script)
./clean.sh
```

### How to use
```
./build/bin/vik <path to a bitcode file>
```
