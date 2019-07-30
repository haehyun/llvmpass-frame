#include <llvm/IR/TypeFinder.h>
#include <llvm/Support/raw_ostream.h>

#include "FuncScanner.h"

using namespace llvm;


void FuncScanner::run(llvm::Module* M, const DataLayout* layout)
{
	errs() << "----------Print Func Info------------\n";
	for(auto iter = M->begin(); iter != M->end(); ++iter) {
		llvm::Function *F = &*iter;
		if(F == nullptr) {
			continue;
		}
		scanner(F, M, structAnalyzer);
	}
	errs() << "----------End of print------------\n\n";
}


void FuncScanner::scanner(llvm::Function* F, llvm::Module* M) 
{
	Type *type;
	llvm::Value *val;
	PointerType *pType;
	std::vector<llvm::Type *> argTyV;

	std::string funcName = F->getName();

	if( F->isVarArg() ){
		errs() << F << ", " << funcName << ": VarArgs\n";
	}
	else if( F->arg_empty() ){
		errs() << F << ", " << funcName << ": Void arg\n";
	}
	else {
		errs() << F << ", " << funcName << "\n";
	}

	return;
}
