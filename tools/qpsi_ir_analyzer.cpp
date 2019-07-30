#include "FuncScanner.h"

#include <llvm/IR/LegacyPassManager.h>	
#include <llvm/IR/LLVMContext.h>		
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/CommandLine.h>	
#include <llvm/Support/Signals.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/PrettyStackTrace.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/SystemUtils.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Bitcode/BitcodeWriterPass.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <llvm/Transforms/Utils/Cloning.h>

#include <omp.h>

using namespace llvm;

static cl::opt<std::string> InputFilename(cl::Positional,
		cl::desc("<input bitcode>"), cl::init("-"));

/**
 * It statrs analysis for libs.
 */
void startAnalysis(llvm::Module *module) {

	llvm::legacy::PassManager Passes;

	outs() << "\nAnalysis started\n";
	outs() << "====================================================\n";

	// omp_set_num_threads(NUMTHREADS);
	FuncScanner* funcScanner = new FuncScanner();
	funcScanner->run(module, &(module->getDataLayout()));

}

int main(int argc, char ** argv) {

	sys::PrintStackTraceOnErrorSignal(argv[0]);
	llvm::PrettyStackTraceProgram X(argc, argv);

	LLVMContext *Context = new LLVMContext();

	std::string OutputFilename;

	cl::ParseCommandLineOptions(argc, argv, "QPSI IR Analyzer\n");
	sys::PrintStackTraceOnErrorSignal(argv[0]);

	PassRegistry &Registry = *PassRegistry::getPassRegistry();

	initializeCore(Registry);
	initializeScalarOpts(Registry);
	initializeIPO(Registry);
	initializeAnalysis(Registry);
	initializeTransformUtils(Registry);
	initializeInstCombine(Registry);
	initializeInstrumentation(Registry);
	initializeTarget(Registry);

	SMDiagnostic Err;

	// Load the input module...
	std::unique_ptr<Module> M1 = parseIRFile(InputFilename, Err, *Context);

	if (!M1) {
		Err.print(argv[0], errs());
		return 1;
	}

	startAnalysis(M1.get());

	return 0;
}

