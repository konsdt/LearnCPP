#include <iostream>

#define PROJECT_NAME "c2p3"

//2.3 Void functions
// Functions do not necessarily have to return a value to the compiler
// To tell the compiler that the function will not return anything the return
// type "void" is used e.g.:
// Thus best practice is not to put a return value at the end of a void function
// since it will return to its caller anyway after the last statement in the 
// functions body
//
//
void printHi() {
    std::cout << "Hi!\n";
}

int main() {
    
    // Call printHi which does not return a value
    printHi();

    return 0;
}
