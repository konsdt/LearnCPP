#include<iostream>
#include<string>
// 9.11 Return by reference and return by address
// Returning by values bares the same disadvantages as passing by value 
// -> it returns a copy of the value, this is fine for basic datatypes but becomes
// expensive for compound datatypes or std::string
// Thus we can also return by reference instead
// The object being returned by reference must exist after the function returns
// otherwise the return by reference will result in a dangling reference
// Therefore a local variable can never be returned by reference
// "Best practice": It should generally be avoided to return references to 
// non-const, since this can easily lead to unexpected behavior if the variable
// is changed later on.
// if a returned reference is used to initialize a normal variable, a copy is made
// of the referenced object (therefore kinda defeats the purpose doesnt it^^)
// There are quite a few cases where returning by reference is sensible,
// e.g. if the object is already passed to the function by reference, since it 
// then automatically exists in the scope of the caller.
// a returned non-const reference can be used by the caller to modify the original
// referenced value
// return by address works exactly the same as return by reference witht the
// exception that a nullptr can alos by returned, thus the caller needs to remember
// to check for a nullptr in order to avoid undefined behavior
// "Best Practice": Prefer return by reference over return by address unless the 
// ability to return "no object" (using nullptr) is important.
//

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; //has static duration,4
                                                             //destryed at end of program
    return s_programName;
}


int main()
{
    std::cout << "This program is named " << getProgramName();

    return 0;
}
