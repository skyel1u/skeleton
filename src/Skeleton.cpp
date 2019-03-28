#include "Skeleton.h"

using namespace llvm;
using namespace std;

namespace llvm
{

Pass *createSkeletonPass()
{
    return new SkeletonPass();
}

char SkeletonPass::ID = 0;
} // namespace llvm

bool SkeletonPass::runOnModule(Module &M)
{
    errs() << "==========================\n";
    Function *F = M.getFunction("main");
    if (F)
    {
        errs() << "Main Function Found!";
        return true;
    }
    else
    {
        errs() << "no main Function found!";
    }
}

static RegisterPass<SkeletonPass> X("run", "Hello world pass", false, false);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                                legacy::PassManagerBase &PM) {
   PM.add(new SkeletonPass());
}
static RegisterStandardPasses
       RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                      registerSkeletonPass);