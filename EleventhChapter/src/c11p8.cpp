#include <iostream>


/*
11.8 Pointers and Arrays
Pointers and arrays are intrinsically related in C++.


In all but two cases when a fixed array is used in an expression, the fixed
array will automatically "decay" (i.e. be implicitly converted) into a pointer 
that points to the first element of an array. 
*/

// when passing a fixed array to a function the c++ compiler will implicitly
// convert the array to the pointer to the array thus the following 2 function
// declarations are identical:
// void printSize(int array[]);
// void printSize(int* array);
// Since most of the time (null terminated strings are the exception) one needs
// to pass the size of an array with the array pointer, since the pointer does not
// know how large the array is, therefore:
// "Best practice:" pass an array with pointer syntax as this makes it clear that 
// it is in fact treated as an array.
// 
// The implicit decay also explains that if the array is changed inside the 
// function the changes will affect the original array

// arrays that are part of structs will not decay when the struct is passed
// to a function, this is a useful tool and is often used to circumvent the decay


int main()
{
    int array[5]{ 9, 7, 5, 3, 1};

    // print address of the array's first element
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    std::cout << "The array decays to a pointer holding address: " << array << '\n';

    // Dereferencing an array returns the value of the first element:
    std::cout << *array;

    char name[]{ "Jason" }; // C-style string also an array
    std::cout << *name << '\n';

    // Differences between pointers and fixed arrays:

    //1. When using sizeof operator:

    // this will print the sizeof(int) * array length
    std::cout << sizeof(array) << '\n';

    int* ptr {array};

    // this will print the size of a pointer
    std::cout << sizeof(ptr) << '\n';

    //2. When using the address-of operator &:

    std::cout << array << '\n';   // type int[5], prints 0x16f3871d0
    std::cout << &array << '\n';  // type int(*)[5], prints 0x16f3871d0

    std::cout << '\n';

    std::cout << ptr << '\n';    // type int* prints 0x16f3871d0
    std::cout << &ptr << '\n';   // type int** prints 0x16b0731b8


    return 0;
}