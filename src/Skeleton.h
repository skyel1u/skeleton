//
// Created by sk on 19-3-18.
//

#ifndef PROJECT_SKELETON_H
#define PROJECT_SKELETON_H

#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {

    class ModulePass;

    ModulePass *createModuleLoopPass();

    class ModuleLoop : public ModulePass {

    public:
        static char ID; // Pass identification, replacement for typeid
        ModuleLoop() : ModulePass(ID) {}
        virtual bool runOnModule(Module &M);
        virtual void getAnalysisUsage(AnalysisUsage &AU) const;

    };
}

#endif //PROJECT_SKELETON_H
