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
// A pointer is an object that holds a memory address(typically of another variable)
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
// Both pointers and references behave similarly, because they both provide a way
// to access another object, differences are:
//  - with pointers one needs to explicitly get the address to point at, this
//    happens implicitly with references
//  - References must be initialized, pointers do not (but should be)
//  - references are not objects, pointer are
//  - references can not be reseated, pointers can change what they are pointing at
//  - references must always be bound to an object, pointers can point to nothing
//  - references are "safe"(outside dangling references), pointers are inherently
//    dangerous
// The size of pointers is depending on the architecture the executeable is 
// compiled for -- a 32-bit executable uses 32-bit memory addresses, therefore
// a pointer is also 32 bits long (4 bytes). Likewise for 64-bit systems
// We can also have dangling pointers
//
// Pointers are more flexible than references but also more dangerous.
//
// 9.7 Null pointers
// Besides a memory address, a pointer can also hold a null value. That means it
// is not pointing at anything. -> Null Pointer
// "Best Practice": Value initialize your pointers (to be null pointers) if you
// are not initializing them with the address of a valid object.
// "Best practice": Use "nullptr" keyword whne you need a null pointer literal
// for initialization, assignement, or passing a null pointer to a function.
// Dereferencing a nullpointer leads to undefined behavior, this mistake is 
// probably the most common one that leads to programs crashing in practice!!!
//
// There is a test to check whether a null pointer is in fact a nullpointer
// See below, also pointers actually implicitly convert to boolean values,
// therefore one does not need to explictily check using the nullptr keyword.
// Instead we can simply check for the pointer e.g.: if (ptr) since a null 
// pointer would implicitly convert to the boolean value false
// Dangling pointers are best avoided by setting all pointers that are not
// pointing to a valid object to be null pointers
// "Best practice": A pointer should either hold the address of a valid object,
// or be set to nullptr. That way we only need to test pointers for null, and
// can assume any non-null pointer is valid.
// It is the programmers responsibility to ensure that all pointers that point
// to an obejct that was destroyed are properly set to null pointer!!!
//
// As dicussed pointers and references both give you the ability to access some
// other object indirectly. Pointers can additionally change what they are pointing
// at and can be pointed at NULL. This makes pointer quite dangerous since the first
// thing makes creating dangling pointers very easy and the second thing could
// when dereferenced crash the program.
// "Best practice": Favor references over pointers unless the additional
// capabilities provided by pointers are needed.
//
// 9.8 Pointers and const
// To declare a pointer to a const value, the const keyword has to be used before
// the pointer's data type.
// The const pointers value can not be changed, the const pointers address however
// can be changed. It could also be pointed at a non const value. In such a case
// the pointer would when dereferenced still not allow to change its value.
// e.g.: const int* ptr { &x };
//
// There is also the possibility to make the pointer itself constant:
// e.g.: int* const ptr { &x }; 
// It must be initialized and the address it contains can not be changed. But
// since the value it points at is not const the value can be changed by 
// dereferencing the pointer.
//
// Const pointer to const value:
// e.g.: const int* const ptr { &x };
// This can not be changed at all, we can only dereference it to get the value
// it is pointing at.
//
//
int main()
{
   
    int* ptr1 { nullptr }; // this is now a null pointer

    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x
    std::cout << &x << '\n'; // print the address of variable x
    std::cout << *(&x) << '\n'; // print the value at the memory address of variable
                                // x (parantheses not required, but make it easier to read)
    int& ref { x }; // a reference to an integer (bound to x)
    int* ptr { &x }; // a pointer to an integer
    
    std::cout << "ref to x: " << ref << '\n';
    std::cout << "ptr to x: " << ptr << '\n';

    // test to check whether the pointer is indeed a nullpointer or not
    if (ptr == nullptr) // explicit test for equivalence
        std::cout << "ptr is null\n";
    else
        std::cout << "ptr is non-null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n");




    return 0;
}
