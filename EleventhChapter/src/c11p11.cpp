#include<iostream>


/*
11.11 Dynamic memory allocation with new and delete
There are three basic types of memory allication:
1. Static memory allocation: for static and global variables: allocated once when
program is run and persists for life of program
2. Automatic memory allocation: for function parameters and local variables: allocated
when relevant block is entered and freed when block is exited
3. Dynamic memory allocation

The first two allocation types have in common, that the size of the variable / array
must be known at compile time and allocation and deallocation happens automatically

These two restrictions are fine most of the time but can cause issues, usually in
cases when there is external input.
In such cases with the first two types best one could do is to make a guess how 
much space an input will require and hope that it is not larger.
Bad for four reasons:
1. wasted memory if not all of it is used
2. how to tell which bits are used? risk of undefined behavior
3. stack overflow if too much of it is reserved
4. artificial limitations and overflow
-> We need to be able to dynamically allocate variables

This dynamic allocation is a way of programs to request memory from the system
that does not come from the stack but instead from the heap

to allocate a dingle variable dynamically the scalar (non-array)form of the "new" operator can be used
Unlike for static or automatic allocation, the program is responsible for requesting
and disposing of dynamically allocated memory

when a variable is dynamically allocated it can also be initialized either via 
direct initialization or via uniform initialization

int* ptr1 { new int (5) }; direct
int* ptr2 { new int {7} }; uniform

when we are done with a dynamically allocated variable we need to explicitly 
tell c++ to free the memory for reuse this is done via the delete operator
to avoid dangling pointers and undefined behavior follow this:
"best practice": Set deleted pointers to nullptr unless they are going out of scope
immediately afterwards.
"best practice": Deleting a null pointer is okay, and does nothing. There is no need to 
conditionalize your delete statements.

11.12 Dynamically allocating arrays
dynamically allocated arrays allows us to choose an array lenght at runtime

The syntax to initialize a dynamic array to zeros is quite simple:
int* array { new[] int[length]{}};

since c++11 initializer list now also work for dynamically allocated arrays

int* array { new int[lenght]{9, 7, 4, 3, 2, 2}};
for types with long names the auto keyword is used often to avoid having to write
the type twice
auto* array { new int[lenght]{9, 7, 4, 3, 2, 2}};

resizing is not build into arrays one could work around this by allocating a new
array, transferring the remaining elements over and deleting the old array,
however this is error prone and not recommended since it becomes problematic
with class types

for this issue the standard library provides a type that allows for resizing 
which will be covered later, this type is called std::vector

*/

//memory leak:
void doSomething()
{
    int* ptr{ new int{} };
}
// this function allocates an integer but never frees it using delete
// after it goes out of scope the program "loses" its memory address and thus
// unneccessarily blocks memory

int main()
{
    std::cout << "Enter a positive integer: ";
    // should be of type std::size_t but since int easily converts to that in practice
    // using this type instead is fine
    int length{};
    std::cin >> length;

    int* array{ new int[length]{} }; // use array new. Note that length does not have to be constant
    std::cout << "I just allocated an array of integers of length " << length << '\n';

    array[0] = 5; // set element 0 to value 5

    delete[] array; // use array delete to deallocate array

    // we do not need to set array to nullptr/0 here because it is going out of
    // scope immediately after this anyway
    return 0;
}