#include <iostream>

// 9.5 Introduction to pointers
// One can use the adress-of operator (&) to retrieve the address assigned to 
// variable x and print that address to the console
// The & symbol can cause confusion, since it can have different meanings depending
// on the context:
//  - When following a type name it denotes an lvalue reference: int& ref
//  - When used in a unary context in an expression, it is the address-of operator: std::cout << &x
//  - When used in a binary context in an expression it is the Bitwise AND operator std::cout x & y;
//
// "The dereference operator (*)":
// The most useful thing that can be done with a address is access the value stored
// at that address. The dereference operator (also called indirection operator)
// returns the value at a given memory address as an lvalue.
// "Key insight": Given a memory address, we can use the dereference operator (*)
// to get the value at that address (as an lvalue)
//
// The address operator (&) and dereference operator (*) work as opposites:
// address-of gets the address of an object, and dereference gets the object at an
// address
//
// "Pointers":
// A pointer is an object that holds a memory address(typically if another variable)
// as its value. This allows us to store the address of some other objects to use later.
// An uninitialized pointer holds a garbage address that when dereferenced will
// lead to undefined behavior
// ->"Best practice": Always initialize your pointers.
// "Key insight": When we use a pointer without a dereference (ptr), we are 
// accessing the address held by the pointer. Modifying this (ptr = &y) changes
// what the pointer is pointing at.
// When we dereference a pointer (*ptr), we are accessing the object being 
// pointed at. Modifying this (*ptr = 6;) changes the value of the object being
// pointed at.
//
//
//
int main()
{
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x
    std::cout << &x << '\n'; // print the address of variable x
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable
                                // x (parantheses not required, but make it easier to read)
    int& ref { x }; // a reference to an integer (bound to x)
    int* ptr; // a pointer to an integer
    return 0;
}
