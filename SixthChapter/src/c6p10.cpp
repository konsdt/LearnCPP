#include<iostream>

// 6.10 Static local variables
// term "static" can be very confusing, since it can mean different things in
// different contexts
// * global variables have static duration: they are created when the program
// starts and are destroyed when it ends
// * the static keyword gives a global variable internal linkage
// Now for LOCAL variables:
// Local variables have automatic duration: created at definition, destroyed
// when the block ends
// * the static keyword gives a local variable static duration:
// created when the program starts and destroyed when it ends, therefore it will
// keep its value even after it goes out of scope
// it is common to prefix static variable with an "s_"
// Most common use case for static local variables is to create unique ids
// this id done to identify objects again later on
//
// 6.11 Scope, duration and linkage summary
// "Scope": determines where the identifier can be accessed within the source code:
//  * block (local) scope (only inside a block)
//  * file (global) scope (from definition to end of file)
// "Duration": determines when it is created and destroyed again
//  * automatic duration: created at definition, destroyed when block is over
//  * static duration: created when program begins, destroyed when it ends
//  * dynamic duration: created and destroyed by programmer request
// "Linkage": determines whether multiple declarations of the same identifier
//  refer to the same object or not
//  * no linkage: id only refers to itself
//  * internal linkage: id can be accessed anywhere within the file it is declared
//  * external linkage: id can be accessed anywhere in the file it is declared in
//    and in other files via a forward declaration
//  "Storage Class identifier":
//   When used as part of an identifier delcaration, the keywords extern and static
//   are storage class identifiers, they determine the storage duration and linkage
//   of the identifiers in this context
//
// 6.12 Using declarations and using directives
// names can either be qualified or unqualified:
// * qualified names: include a qualified scope either by the scope resolution
//   operator or by other things like the class or a pointer to a class object
// * unqualified names: do not include a scoping qualifier
// "Using declarations":
// allows to use an unqualified name as an alias for a qualified name e.g.
// this is considered safe and acceptable as long as it is used inside a function
// "Using directive":
// Should be avoided in modern c++, since they can easily cause "ambiguous symbol"
// errors
// if using declarations or directives are used inside a block they have block
// scope
// if they are used in the global namespace they have file scope
// /Best practice/: Prefer explicit namespaces over using statements. Avoid using
// using directives whenever possible. Using declarations are okay to use inside blocks.
// 
// 6.13 Inline function 
// a call to a function generates some overhead, this overhead can take up more
// cpu time and memory then the function body execution.
// Therefore compilers have the possibility to expand the functions into the line
// -> inline functions
// compilers are very good at deciding if to do so or not nowadays, there are three 
// function categories:
// * can not be inlined
// * may be inlined
// * must be inlined
// most of the functions fall into the middle category
// for historic reasons there is an inline keyword for functions. today this 
// is just a hint, and wronfully used can still cause harm
// /Best practice/: Do not use the inline keyword to request inline expansion
// for your functions.
// For inlining the compiler must see the whole functions, Since ODR says you
// should not define them in the header this can be a problem.
// The inline keyword allows for multiple definitions, this concerns variables 
// and functions. Still one should try to avoid this, but there are some examples
// where it is usefull.
//
// 6.14 Constexpr and consteval functions
// Constexpr functions can be evaluated at compile time.
// To be eligibel for compile time evaluation a function is not allowed to call
// any non constexpr functions and the call to the functions must have constexpr
// arguments.
// /Best Practice/: One should use a constexpr keyword for a function that is 
// supposed to return a compile time keyword.
// constexpr functions are implicitly inline
// as a result they need to be defined in every function and thus are often 
// defined inside the headers
// They allow for evalutation at runtime if they are passed non constexpr 
// arguments.
// Still they are not always evaluated at compile time. This is only the case
// if they are evaluated at a place where a constexpr is required.
// Therefore a compilers optimization setting may determine the evaluation 
// time of a function.
// Thus a constexpr function is better thought of as "can be used in a constexpr"
// not as "is evaluated at compile time".
// "consteval": c++20 introduces this keyword to force a function to evaluate at 
// compile time.
// /Best Practice/: Use consteval if you have a function that must run at compile
// time for some reason (e.g. performance).
// "consteval auto compileTime": is a neat helper function that allows to still
// have run-tim evaluation if we really cannot have compile time evaluation.

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; //makes a copy of the variable and returns it, while the
                       //actual variable is incremented by 1
}

// static local variables can be made constant, this helps if a very expensive
// object needs to be initialized at the beginning of a function, but it does not
// change later on, thus you can make it static so it will only be initialized once
// even though the function is called multiple times
// /Best practice/: Avoid the use of static local variables unless the variable
// never needs to be reset.




void incrementAndPrint()
{
    int value{ 1 }; //value is created here
    ++value;
    std::cout << value << '\n';
} //value is destroyed here

void staticIncrementAndPrint()
{
    static int s_value{ 1 }; //value is created here
    ++s_value;
    std::cout << s_value << '\n';
} //value is not destroyed here, but becomes inaccessible because it goes out 
  //of scope


int main()
{
    using std::cout;
    cout << "Hello world!" << '\n';
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();
    staticIncrementAndPrint();
    staticIncrementAndPrint();
    staticIncrementAndPrint();
    return 0;
 }
