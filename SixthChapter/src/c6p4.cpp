#include<iostream>

// 6.4 Global variables
// global variables are declared at the top of a file, below the includes, but
// above any code
// /Best practice/: Use a "g_" prefix for global variables to help differentiate
// them from local variables
// global variables have "file scope" also called "global scope" or "global
// namespace scope"
// they are created when the program starts and are destroyed when it ends, this
// is called "static duration", therefore sometimes they are calles "static variables"
// const global variables always need to be initialized whereas non constant
// variables can be uninitialized
// refresher: constexpr are compile time constant, there value is determined
// at compile time, const are runtime expressions they can be determined by any
// runtime expression like a function "getNumber()" (user input)
// /Warning/: Use of non-constant global expressions should be avoided altogether
// 
// 6.5 Variable shadowing:
// This happens if in a nested block a variable appears that has the same identifier
// as a variable defined in the outer block -> the inner variable has priority and
// the outer block variable is temporarily hidden until the end of the block
// "Shadowing of global variables":
// Wherever a local variable with the same id as a global variable is in scope
// the global variable is hidden. So to say the local variable will shadow the 
// global variable.
// But we can use the scope resoultion operator without prefix to instead get
// the global variable
// /Best Practice/: Avoid variable shadowing!.
//
// 6.6 Internal linkage
// "internal linkage": identifier can be seen within the file in which it is used
// but is not accessible from other files
// global variables can be made internal by using the "static keyword"
// the use of the "static" keyword is an example of a "storage class specifier"
// these class specifiers set the object's linkage and its storage duration
// but they do not determine the object's scope
// the most commonly used "storage class specifiers" are "static", "extern" and
// "mutable"
// Function identifiers have the same linkage properties as variable identifiers
// do. 
// BUT: Function identifiers default to external linkage and can be set to internal
// linkage via the "static" keyword
//
// global variable with internal linkage
static int g_y {};
// const and constexpr variables are internal variables by default,
// therefore they do not require the static keyword!
// If it is used it will be ignored
//
// //6.7 External linkage and variable forward declarations
// identifiers with external linkage can be seen in the file in which they are 
// defined but also in other code files via forward declaration
// in that sense such identifiers are truly "global" since they can be used 
// anywhere in the code file
void sayHi(); //forward declaration of sayHi function in sayHi.cpp
// the forward declaration satisfys the compiler and the linker is able to link
// the function call to the function definition
// to use global variables that are extern from another file, they also need
// forward declarations in the file they are supposed to be used in.
// const variables need to always have the extern keyword to allow for external
// linkage. normal global variable only need the extern keyword in there 
// forward linkage, since there definition is set to external linkage by default
// constexpr can be given external linkage, but this should never be done since
// the compiler needs to know the constexpr value at  compile time and it will
// not be able to see the value if it is defined inside another cpp file.
// On the other hand forward declarations of functions do not require the "extern"
// keyword.
//
// 6.8 Why (non-const) global variables are evil!!!
// Biggest reason: there value can be changed by any function and there is no 
// easy way for the programmer to know that this will happen
// //Best practice/: Use local variables instead of global variables whenever
// possible.
// Criteria that rectify the use of a global variable:
// there should only ever be one of the thing the variable represents in your 
// program, and its use should be ubiquitous (allgegenwärtig) throughout the
// program.
// Tips for the usage of global variables:
// * put them in namespaces!
// * make sure it can only be accessed from within the file it is declared in
//   and then use access function like in the example below
//   If you ever want to change the underlying implementation you only need
//   to rewrite the access function and you will not have to change every piece
//   of code that uses the global external variable explicitly
namespace constants
{
    constexpr double gravity { 9.8 };
}

double getGravity()
{
    return constants::gravity;
}
// * if you ever need to write an otherwise standalone function that uses the 
// global variable, do not use it directly, instead pass it in as an argument
// this allows to keep the modularity -> if the variable ever needs to change
// you can simply pass it a different argument.
//
// 6.9 Sharing global constants across multiple files (using inline variables)
// Before c++17 the most common way was as follows:
// 1. Create a header file to hold these constants
// 2. Inside this header file, define a namespace
// 3. Add all your constants inside the namespace
// 4. #include the header file whenever you need it
#include "constants.h"
// this method has a few downsides:
// changing a constant requires recompiling every file that includes the constant
// this can lead to lenthy recompile times for lenthy projects
// if the constants are large in size including all of them in every file in
// which one of them is needed can use a lot of memory
// One alternative is defining the constants in a .cpp file and only putting
// the forward declarations into the headers
// this leads to other problems -> the constants now are not compile time constants
// anymore but instead runtime constants, therefore they are not optimized as 
// much and can not be used in places where compile time constants are required
// /Key insight/: for variables to be useable in compile-time context such as array
// sizes, te compiler needs the variable definition in the same file, not only
// the forward declaration
// THUS: prefer defining them inside the header, if that causes problems, some
// of them might be moved to a cpp file instead
// "Inline variables":
// the inline keyword was introduced with c++17, it avoids the problem of having
// 10 definitions of the same constants in memory if you include them in 10 different
// files, the compiler automatically settles on only one representation of 
// variables with the same identifier in memory and therefore saves a lot of it
// /Best practice/: if possible use "inline" keyword for global constants!:



// Variables declared outside of a function are global variables
int g_x {}; // global variable g_x

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    g_x = 3;
    std::cout << g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << g_x << '\n';

    // global variables can be seen an used everywher in the file
    g_x = 5;
    std::cout << g_x << '\n';
    sayHi();
    std::cout << '\n';
    std::cout << getGravity() << '\n';
    // output avogadro constant from header
    std::cout << constants::avogadro << '\n';

    return 0;

}
// g_x goes out of scope here
