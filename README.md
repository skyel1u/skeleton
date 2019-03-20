# README

My work.

## Run the Module Pass

```sh
~/Desktop 
➜ $LLVM_HOME/bin/opt -load ~/Desktop/pass-example/cmake-build-debug/src/libSkeletonPass.so -hello < 1_6.bc
WARNING: You're attempting to print out a bitcode file.
This is inadvisable as it may cause display problems. If
you REALLY want to taste LLVM bitcode first-hand, you
can force output with the `-f' option.

==========================
Main Function Found!%                                                           
~/Desktop 
➜ $LLVM_HOME/bin/opt -load ~/Desktop/pass-example/cmake-build-debug/src/libSkeletonPass.so -hello < tt.bc 
WARNING: You're attempting to print out a bitcode file.
This is inadvisable as it may cause display problems. If
you REALLY want to taste LLVM bitcode first-hand, you
can force output with the `-f' option.

==========================
no main Function found!% 
```

