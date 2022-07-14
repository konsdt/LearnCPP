#include<iostream>

// 4.13 constant variables and symbolic constants
// "constant variable": variables with values that can not be changed
// "const" key word will make variable constant, best practice: place it before
// type
// const variable must be initialized
// Dont use a const variable when passing by a value(e.g. to a function)
// Sont use const for return values
// "symbolic constant": name that is given to a constant value, constant variables
// are one type of symboluic constant since the variable has a name and a constant
// value
// Prefer constanct variables over object-like macros with substitution text.
// sometimes constatns have to be used in multiple files -> declare them
// centrally, how this is done we will see later in 6.9
// 4.14 compile time constants, constant expressions
// constant expressions are optimized by the compiler, they will not be executed
// every single time, but there result will be compiled e.g: 3 + 4 will be optimzed
// to just 7
// compile time constants are intialized constants
// runtime constants are constants that will be initialized by something variable
// but do not change afterwards
// best practice: any variable that should not be modifiable after initialization
// and whose initializer is known at compile-time should be declared as "constexpr"
// Any variable tht should not be modifiable after initialization and whose initializer
// is not known at compile-time should be declared as "const"

int getNumber() 
{
    std::cout << "Enter an integer: ";
    int y{};
    std::cin >> y;

    return y;
}


int main()
{
    const double earthGravity{ 9.8 }; // m/s compile time constant
    const int y{getNumber()};   // runtime constant
    std::cout << earthGravity + y ; //is a runtime expression
    return 0;
}
