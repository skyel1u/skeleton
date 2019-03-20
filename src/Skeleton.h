//
// Created by sk on 19-3-18.
//

#ifndef PROJECT_SKELETON_H
#define PROJECT_SKELETON_H

#include "llvm/Pass.h"

namespace llvm {
    Pass *createSimpleInvoker();
    void initializeSimpleInvokerPass(PassRegistry &Registry);
}

#endif //PROJECT_SKELETON_H
