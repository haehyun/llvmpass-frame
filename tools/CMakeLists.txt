
#if(DEFINED IN_SOURCE_BUILD)
#    set(LLVM_LINK_COMPONENTS BitWriter Core IPO IrReader InstCombine Instrumentation Target Linker Analysis ScalarOpts Support Svf Cudd)
#    add_llvm_tool( ssca ssca.cpp )
#else()
    llvm_map_components_to_libnames(llvm_libs BitWriter Core IPO IrReader InstCombine Instrumentation Target Linker Analysis ScalarOpts Support )
    add_executable( qpsi_ir_analyzer qpsi_ir_analyzer.cpp )

    target_link_libraries( qpsi_ir_analyzer LLVMqpsir ${llvm_libs} )

    set_target_properties( qpsi_ir_analyzer PROPERTIES
                           RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
#endif()
