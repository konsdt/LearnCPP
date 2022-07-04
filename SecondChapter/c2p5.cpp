#include <iostream>


// 2.5 Introduction to local scope
// Local variables are, function parameters or variables that are designed 
// inside the functions body.
// function parameters are instantiated in memory at call of function and
// variables at point of initilization 
// They are destroyed in opposite order of creation

// lifetime is a runtime property
// scope is a compile-time property, as long as and identifier can be accessed it
// is "in scope" otherwise it is "out of scope"
// a local variable goes out of scope when it is destroyed,
// not all variables are destroyed when going out of scope


// best practice: define your local variables as close to your first call as
// reasonable



int add(int x, int y) // parameters x and y are created and enter scope here
{
    // x and y are visible and usable inside this function only
    return x + y; 
    
} // y and x are destroyed and go out of scope here


int main() 
{
    int a{ 5 }; // variable a is created, initialized and enters scope here
    int b{ 6 }; // variable a is created, initialized and enters scope here

    // a and b are usable within this function only
    std::cout << add(a, b) << "\n"; // calls function add with x=5 and y=6
                                    
    return 0;
} // b and a go out of scope and are destroyed here 

