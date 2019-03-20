#include "Skeleton.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
using namespace llvm;
using namespace std;

namespace llvm {
    class SkeletonPass : public ModulePass {
    public:
        static  char  ID;
        SkeletonPass() : ModulePass(ID) {}
        bool runOnModule(Module &M) override;
        virtual StringRef getPassName() const  override {
            return "Skeleton";
        }
    };

    Pass *createSkeletonPass() {
        return new SkeletonPass();
    }

    char SkeletonPass::ID = 0;
}

bool SkeletonPass::runOnModule(Module &M) {
    errs() << "==========================\n";
    Function *F = M.getFunction("main");
    if (F) {
        errs() << "Main Function Found!";
        return true;
    } else {
        errs() << "no main Function found!";
    }
}

static  RegisterPass<SkeletonPass> X("hello", "Hello world pass", false, false);


// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
//static void registerSkeletonPass(const PassManagerBuilder &,
//                                 legacy::PassManagerBase &PM) {
//    PM.add(new SkeletonPass());
//}
//static RegisterStandardPasses
//        RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
//                       registerSkeletonPass);