set(SOURCES
    FuncScanner.cpp
    )

add_llvm_loadable_module(qpsir ${SOURCES})
add_llvm_Library(LLVMqpsir ${SOURCES})


if(DEFINED IN_SOURCE_BUILD)
    add_dependencies(qpsir intrinsics_gen)
    add_dependencies(LLVMqpsir intrinsics_gen)
endif()
