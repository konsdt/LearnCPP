#include <iostream>

#define PROJECT_NAME "c2p1"

//2.1 Functions
// A function is a reusable collection of statements that execute sequent-
// ially. These are designed to do a specific job.
// Nested functions in CPP are not supported
// That means a function can not be defined inside another function, it can only
// be executed inside another function

void doB() {
    std::cout << "In doB()\n";
}
// functions calling functions calling functions
void doA() {
    std::cout << "In doA()\n";

    doB();

    std::cout << "Ending doA()\n";
}

// Definition of a user defined function
void doPrint() {    // doPrint is the called function in this example
    std::cout << "In doPrint()\n";
}


// Definition of function main
int main() {
    

    std::cout << "Starting main()\n";
    // Interrupt main by making a call to a different function (callee) main()
    // is the caller
    doPrint();
    
    doA();

    std::cout  << "Ending main()\n";
    
        return 0;
}
