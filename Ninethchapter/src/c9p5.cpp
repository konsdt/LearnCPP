#include <iostream>
#include <string>


// 9.5 Pass by lvalue reference
// Why are references useful? Until now we passed parameters of functions by value.
// This means a copy of the parameter is created for the function and  destroyed at
// the end of it. For fundamental data types this is cheap, but there are types
// that are very expensive to copy.
// for example most types provided by the standard library are class types 
// that are extremely expensive to copy (e.g.: std::string)
// Alternatively one can pass by reference to avoid making a copy of the passed
// parameters
// to do this the function parameter needs to be declared as reference:
// "key insight": Pass by reference allows us to pass arguments to a function 
// without making copies of those arguments each time the function is called.
// "key insight": Passing values by reference to non-const allows us to write functions
// that modify the value of arguments passed in.
// pass by reference to non-const can only accept modifiable lvalue arguments,
// that means it limits the usefulness of pass by reference to non-const as it means
// we can not pass const variables or literals....
// the easiest and most straight forward workaround for this is to pass by const reference
// this still keeps the main benefit (not having to make a copy of the argument)
// "Best Practice": Favor passing by const reference over passing by non-const
// reference unless you ahve a specific reason to do otherwise (e.g. the function
// needs to change the value of an argument)
// it is no problem to have a function with several arguments that are passed in
// different ways
// When to pass by reference?
// "Best Practice": Pass fundamental types by valuem and class (or struct) types 
// by const reference.
// Why not pass everything by reference?
// FOr objects that are cheap to copy, the cost of copying is similar to the cost of
// binding, so we favor pass by value so the code generated will be faster
// for objects that are expensive to copy the cost of the copy dominates, so we favor
// pass by (const) reference to avoid making a copy
//
// but what means cheap to copy?: we can say an object T is cheap to copy 
// if sizeof(T) <= 2 * sizeof(void*) and has no additional setup cost
// function preprocessor macro:
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))


struct S
{
    double a, b, c;
};


void printValueRef(std::string& y)
{
    std::cout << y << '\n';
}


void printValue(std::string y)
{
    std::cout << y << '\n';
} //y is destroyed here


int main() 
{
    std::string x { "Hello world!" }; // x is a std::string
                             
    printValue(x); // x is passed by value (copied) into parameter y (expensive)
    printValueRef(x); // x is now passed by reference into reference parameter y
    
    std::cout << std::boolalpha; // print True or False rather than 1 or 0
    std::cout << isSmall(int) << " int \n";
    std::cout << isSmall(double) << " double \n";
    std::cout << isSmall(S) << " struct \n";


    return 0;
}
