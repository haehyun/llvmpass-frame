# add_subdirectory(SVF)

# Due to a mutual dependencies, all the sub projects of the SVG are merged here
# Otherwise it is impossible to load the dependencies in opt
# NOTE: if the SVF should be linked into opt, we should probably use the individual sub projects here, rather than the combined project 
set(SOURCES
    FuncScanner.cpp
    )

add_llvm_loadable_module(qpsir ${SOURCES})
add_llvm_Library(LLVMqpsir ${SOURCES})


if(DEFINED IN_SOURCE_BUILD)
    add_dependencies(qpsir intrinsics_gen)
    add_dependencies(LLVMqpsir intrinsics_gen)
endif()
