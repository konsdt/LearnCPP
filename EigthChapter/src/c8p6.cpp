#include <iostream>

// 8.6 Typedefs and type aliases
// "using" is a keyword that creates an alias for an existing data type
using Distance = double; //define Distance as an alias for type double

// "Best practice":
// type aliases should be named starting with a capital letter and should not
// have a suffix
// A type alias has block scope.. so the above example has global scope
// aliases with global scope should usually be put in a header file when
// used in several files
// for backwards compatibility type aliases can also be done using the
// keyword "typedef" it is however best practice to avoid this and use "using" 
// instead
//
// Used for:
//  * platform independent coding
//  * complex types
//  * readability
//  * easier code maintenance
// It is best to only use them when it really has a clear benefit to do so
//
// 8.7 Type deduction for objects using the auto keyword
// type deduction or inference is a feature that allwos the compiler to deduce the
// type of an object from the objects initializer
// it has a few pitfalls but also a lot af advantages 
// ->"Best Practice": use type deduction for your variables, unless you need to
// commit to a specific type.
//
// 8.8 Type deduction for functions
// "Best practice": Favor explicit return types over function return type
// deduction for normal functions.
//
//
//
int add(int a, int b)
{
    return a + b;
}

int main() {
    
    auto d { 5.0 }; // 5.0 is a double literal, so d will be type double
    auto i { 1 + 2 }; // 1 + 2 evaluates to an int, i will be type int
    auto x { i }; // i is an int, so x will be type int too
    // it is also possible to use type deduction if the initializer is a 
    // function call:
    auto sum { add(5, 6) };
    
    return 0;
}
