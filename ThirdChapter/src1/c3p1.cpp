#include <iostream>

#define PROJECT_NAME "Debugging"

// 3.1 Syntax and semantic errors
// syntax error: faulty language grammar (missing ;, undeclared variables, etc)
// semantic error: grammar correct but program does not do what it is intended to
//
// Debugging strategy:
// 1. Find the root cause
// 2. Understand the problem
// 3. Determine a fix
// 4. Repari the issue
// 5. Retest
//
// Use debugging statements (outputs), as std::cout might be buffered for 
// performance reasons use std::cerr instead. This will output immediately
// For finding theses statements again after finishing debugging do not
// indent them
// While adding printing statements is a viable tactic it isnt great:
// 1. Debug statements clutter the code
// 2. They clutter the output of your program
// 3. Must be removed after -> non-reuseable
// 4. Require code modifications which could cause new bugs
//
// More Debugging tactics:
// 1. Conditionalize prints via preprocessor defines -> lets you keep
// debugging statements for the future
// 2. use a logger:
//    A file that records everything occuring in software e.g there is the plog
//    logger... can be downloaded from git and its header dir can be included
//    in the project as include directory... I am kind of too lazy to do this 
//    right now since I most likely wont use this any time soon, but now I
//    know the concept https://github.com/SergiusTheBest/plog
//    The remainder of this chapter we will learn how to use the integrated
//    debugger. So I guess I will learn a little more about meson in the future


int getValue()
{
std::cerr << "getValue() is called\n";
    return 4;
}

int main()
{
std::cerr << "main() is called\n";
    std::cout << getValue;
    return 0;
}
