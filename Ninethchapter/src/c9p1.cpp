#include <iostream>

#define PROJECT_NAME "CompoundtypesReferencesAndPointers"

// 9.1 Introduction to compound data types
// Also sometimes calles composite data types are data types that can be constructed
// from fundamental data types, the following compound types are supported by c++:
// * Functions
// * Arrays
// * Pointer types:
//      - Pointer to object
//      - Pointer to member function
// * Pointer to member types:
//      - Pointer to data member
//      - Pointer to member function
// * Reference types:
//      - L-value references
//      - R-value references
// * Enumerated types:
//      - Unscoped enumerations
//      - Scoped enumerations
// * Class types:
//      - Structs
//      - Classes
//      - Unions
//
// 9.2 Value categories (lvalues and rvalues)
// Expressions can do three things:
// - Produce a value
// - Produce a side effect
// - Evaluate to objects or functions
// To determine what a expression should evaluate to, an expression has two properties:
// a type and a value category
// "The type of an expression":
// the type is equivalent to the type of the value, object or function that results
// from the evaluated expression
// the type must be determinable at compile type while the value may be determined
// at run time
// "The value category of an expressions":
// before c++11 there were only two value categories: lvalues and rvalue
// after c++11 three more value categories were added(glvalue, prvalue, xvalue)
// "Lvalue and rvalue expressions":
// an lvalue is an expression that evaluates to an identifieable object or function
// entities with an identity can be accessed via an identifier, reference or pointer
// and typically have a lifetime linger than a single expression or statement
// they come in two subtypes: modifiable lvalue e.g.: int x {};
// and non-modifiable lvalue e.g: const double d{2};
// an rvalue is an expression that is not an lvalue, common rvalues are literals,
// return value of functions and operators. They are not identifieable that means
// they exist only within the scope of the expression in which they are used
// 
// for example an assignement requires the left operand to be an lvalue expression
// and the right operand to be an rvalue expression
// But lvalues will implicitly convert to rvalues if they can, thus an lvalue can 
// be used wherever an rvalue is required
//
// "Key insight":
// As a rule of thumb to identify lvalue and rvalue expressions:
// lvalue expressions are those that evaluate to variables or other identifiable
// objects that persist beyond the end of the expression.
// rvalue expressions are thise that evaluate to literals or the returned value
// of functions and operators that are discarded at the end of the expression
//
// 9.3 Lvalue references
// A reference is an alias for an existing object. Once a reference is defined,
// any operation applied to the reference is applied to the object being referenced.
// -> it is essentially identical to the object being referenced
// An lvalue reference (commonly just called reference since prior to c++11 there
// was only one type of reference) acts as an alias to an existing lvalue.
// to declare a reference and ampersand is used in the type declaration
// "Best practice": When defining a reference, place the ampersand next to the type
// (not the reference variable's name)
// values can be modified through an lvalue reference
// all lvalue references must be initialized
// lvalue references must be bound to a modifiable value (not const)
// references cant be reseated (changed to refer to another object)
// they follow the same scoping and duration rules as that normal variables do
// references and referents have independet lifetimes, both can be destroyed without
// this affection the other
// if the referent is destroyed before the reference, the reference is 
// refering to an object that no longer exists. This is called "dangling reference"
// This can lead to undefined behavior
// references are not objects, they are not required to exist ofr occupy storage.
//
// 
//

int main() {
    
    int x { 5 }; // x is a normal integer variable
    int& ref { x }; // ref is an lvalue that can now be used as an alias for variable x
    
    std::cout << x << '\n';
    std::cout << ref << '\n';

    ref = 6;

    std::cout << x << ref << '\n'; //print 66


    return 0;
}
