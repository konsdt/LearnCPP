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
// 6.3 Local variables
// Local variables have block scope -> they are in scope from point of definition
// until the end of the block
// All variable names in a scope must be unique
// passed values enter the function scope -> defining a variable inside the function
// that has the same name as a variable that is passed to it leads to a naming collision
// "Storage duration":
// Governs when and how a variable will be created and destroyed ->in most cases lifetime
// Local variables have automatic storage duration, which means they are created at
// their point of definition and destroyed at the end of the block they are defined
// in, this is why they are sometimes called "automatic variables"
// local variables have no linkage: there are no other declarations of that variable
// that refers to the same object
// /Best Practice/:
// Variables should be defined in the most limited space
// Do not create a nested block for the singel purpose to force variables going
// out of scope earlier, if considering this in almost all cases it would be better
// to define the nested block inside an own function
// /
//
//
//
namespace foo // define a namespace that is called foo
{


    int getInteger()
    {
        int x { };
        std::cin >> x;
        return x;
    }


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

     // quiz time
    std::cout << "Enter an integer: ";
    int smaller { foo::getInteger() };
    std::cout << "Enter a larger integer: ";
    int larger { foo::getInteger() };
    
    if (smaller > larger)
    {
        std::cout << "Swapping variables.." << '\n';
        int temporary { smaller };
        smaller = larger;
        larger = temporary;
    } //temporary dies here and is not accessible anymore
    
    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    int x { 2 }; //local variable
    {
        int x { 3 }; // x refers to different object in a different scope/block
    } //goes out of scope here



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
