#include <iostream>

namespace math
{


    int add(int x, int y)
    {
        return x + y;
    }
    
    double add(double x, double y)
    {
        return x + y;
    }

}


// 8.9 Introduction to function overloading
// this is a method that allows to create multiple functions with the same
// name, as long as every identically named function has different parameter types
// every function (in the same scope) that shares a name is called "overloaded"
// the compiler will automatically try to use the correct version of the function
// based on the types of the parameters that are provided "overload resolution"
// "Best Practice:" Use function overloading top make your program simpler
//
// 8.10 FUnction overload differentiation
// The type of parameters and the number of parameters can be used to 
// differentiate an overloaded funtion
// The return type of a function is not considered for differentiation
//
// 8.11 Function overload resolution and ambiguous matches
// 1. Exact Match of expected vs. given parameter types
// 2. Find a match via numerc promotion to the arguments
// 3. Find a match by numeric conversions
// -> Matches by numeric promotion take precedent over matches by numeric conversion
// 4. Find a match by user-defined conversions
// 5. Look for a matching function that uses ellipsis (...)
// 6. Compiler Error
//
// "ambiguous match": the compiler finds multiple functions that can match the call
// -> this will result in a compile time error
//
// 8.10 Default arguments
// a default argument is a default value provided for a function parameter
// they can only be provided for the right most function parameters (but all can
// have a default value)
// they can only be declared once
// -> "Best practice": if the function has a forward declaration put the default
// argument there. Otherwise put it in the function definition.
// but the parameters can be varied in overloaded functions. This can quickly lead
// to ambigious function call erros, thus one has to be extra careful there.
// 


int main() {
    
    std::cout << math::add(1, 2); //calls add(int, int)
    std::cout << '\n';
    std::cout << math::add(1.2, 3.4); //calls add(double, double)

    return 0;
}
