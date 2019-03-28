//
// Created by sk on 19-3-18.
//

#ifndef PROJECT_SKELETON_H
#define PROJECT_SKELETON_H

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

namespace llvm
{
Pass *createSkeletonPass();
void initializeSkeletonPass(PassRegistry &Registry);

class SkeletonPass : public ModulePass
{
  public:
    static char ID;
    SkeletonPass() : ModulePass(ID) {}
    bool runOnModule(Module &M) override;
    virtual StringRef getPassName() const override
    {
        return "Skeleton";
    }
};
} // namespace llvm

#endif //PROJECT_SKELETON_H