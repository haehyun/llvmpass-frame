#ifndef FUNC_SCANNER_H_ 
#define FUNC_SCANNER_H_ 

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/TypeBuilder.h"
#include "llvm/IR/TypeFinder.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

class FuncScanner {		
public:
	FuncScanner() {}
	void run(llvm::Module* M, const llvm::DataLayout* layout);

private:
	void scanner(llvm::Function* F, llvm::Module* M);
};

#endif // FUNC_SCANNER_H_ 
