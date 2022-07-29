#include "circle.h"
#include "growth.h"

#include <iostream>

#define PROJECT_NAME "ScopeDurationLinkage"


// 6.1 Compound statements
// also called "block/block statement" is a group of zero or more statements
// that is treated by the compiler as a single statement
// They begin with { and end with } no semicolon is needed at the end of it
// blocks can be nested, while functions can't be
// if statements need a block only if they execute more than a single statement
// The nesting level of a function is the maximum number of nested blocks you
// can be inside at any point in the function, c++ recommends compilers to support
// up to 256 nesting levels, this is however not followed by every compiler
// /Best practice/: Keep the nesting level of your functions to 3 or less.
// If it needs more levels refracture it into subfunctions.
//
// 6.2 User-defined namespaces and the scope resolution operator
// It is possible to define your own namespaces by namespace name {}
// everything that is defined inside such a namespace now is not accessible
// from the global namespace
// This is done especially in very large projects in order to avoid naming
// collisions, such that two functions have the same identifier inside the same
// namespace
// If one wants to access anything inside the namespace you have to use one of
// two possible methods to tell the compiler in whiche namespace to look:
// 1. scope resolution operator ::
// 2. using statements
// If in a certain namespace where a function id exists that is the same as a
// function id that exists in the global namespace, the scope resolution 
// operator can be used without a prefix namespace e.g. ::print()
// then the version of the function from the global namespace is used instead of
// the one that lives inside the same namespace
// namespaces can be nested
// if the header uses a namespace, the linking source file needs to use the same
// namespace
//
namespace foo // define a namespace that is called foo
{
    //define function doSomething that belongs to namespace foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

// nested namespace declaration
namespace foo::blah 
{ 
    int add(int x, int y)
    {
        return x + y;
    }
}


namespace goo // define a namespace that is called goo
{
    //define function doSomething that belongs to namespace goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main() 
{
    std::cout << foo::doSomething(4, 3) << '\n';     
    std::cout << goo::doSomething(4, 3) << '\n';     
 
    // cpp allows to set namespace aliases for example:
    // only available for cpp versions of 20 and above
    namespace active = foo::blah;

    std::cout << active::add(1, 2) << '\n'; 


    //namespaces with the same identifier can be defined in several places
    //all contents are considered to belong to the same namespace
    //like the following two constants that are defined in the
    std::cout << basicMath::pi << '\n';
    std::cout << basicMath::e << '\n';
    return 0;
}
