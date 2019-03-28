#include "Skeleton.h"

using namespace llvm;

void ModuleLoop::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.addRequired<LoopInfoWrapperPass>();
}

char ModuleLoop::ID = 0;
ModulePass *llvm::createModuleLoopPass() { return new ModuleLoop(); }

bool ModuleLoop::runOnModule(Module &M) {

    for (Module::iterator func_iter = M.begin(), func_iter_end = M.end(); func_iter != func_iter_end; ++func_iter) {
        Function &F = *func_iter;
        if (F.isDeclaration()) {
            LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
        }

    }
    return false;
}

static RegisterPass<ModuleLoop> X("run", "LoopPass within ModulePass");