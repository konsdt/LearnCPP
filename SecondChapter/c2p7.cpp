#include <iostream>

// 2.7 Forward declaration and definition
// Programs execute sequentially -> functions can not be used before they were
// defined
//
// best practice with compiler errors: always try to resolve the first error 
// produced first and the compile again
//
// Two options 1. Define function before

int add(int x, int y) 
{
    return x + y;
}

// Option 2 is a forward declaration
// this allows to tell the compiler about the existence of a function before the
// functions body is defined, thus it will understand that we are making a 
// function call and can check whether the function is called correctly

//function prototype includes return type, name, parameters and semicolon but not
//the function body
int multiply(int x, int y);
// forward function declarations do not need to include parameter names:
// int multiply(int, int); is valid aswell
// But is best practice to keep the parameter names as it will allow you to
// understand the purpose of the function better without looking it up
//
//Difference Declaration and Definition:
//
//definition is the actual implementation of the function and satisfys the
//linker 
//
//declaration is all that is necessary to satisfy the compiler, in c++ all 
//definitions serve as declarations
//
//Functions that have the same identifier but different parameters are considered
//to be distinct functions later "function overloading"

int main() 
{
    std::cout << " The sum of 3 and 4 is: " << add(3, 4) << "\n";
    
    std::cout << " The product of 3 and 4 is: " << multiply(3, 4);
    return 0;
}

int multiply(int x, int y)
{
    return x * y;
}
