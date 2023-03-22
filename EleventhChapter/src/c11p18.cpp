#include<array>
#include<cstddef>
#include<iostream>
#include<vector>
/*
11.18 Introduction to iterators
There are several different ways to iterate through an array:
- Indexing with:
    * for-loop
    * while-loop
- Pointers and Pointer arithmetic
- range-based for-loops
range-based for-loops are the most interesting out of all of them since they
use "iterators":
An iterator is an object which is designed to traverse through a container
the container can be anything lkike a values in a list or characters in a string
while traversing the iterator provides access to all the elements in the container

all types that have both .begin() and .end() member functions, or that can be used with
std::begin and std::end() are usable in range-based for-loops

later we will learn how to add functions to my custom types thus making them useable in 
a range-based for-loop aswell

Iterator invalidation (danling iterators)
iterators can be left dankgling when the elements they are supposed to iterate over
change address or are destroyed

this can happen due to operations on the container, like for example if a std::vector
object is expanded by an element the addresses of the object can change
good c++ reference documentation should specify which container operations
might have effects on iterators!
*/


int main() 
{

    std::array data { 0, 1, 2, 3, 4, 5, 6 };
    std::size_t length { std::size(data) };

    //while loop eiht explicit index
    std::size_t index { 0 };
    while (index < length)
    {
        std::cout << data[index] << " ";
        ++index;
    }
    std::cout << '\n';

    // for loop with explicit index
    for (index = 0; index < length; ++index)
    {
        std::cout << data[index] << ' ';
    }
    std::cout << '\n';

    // for loop with ponter (Note: ptr cant be const, because we increment it)
    for (auto ptr{ &data[0] }; ptr != (&data[0] + length); ++ptr)
    {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';

    // range-based for-loop
    for (int i : data)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
 
    std::vector v {1, 2, 3, 4, 5, 6, 7, };
    auto it{ v.begin() };

    ++it; //move to second element
    std::cout << *it << '\n';
 
    v.erase(it); // erase the element currently being iterated over

    //erase() invalidates iterators to the erased element (and subsequent elements)
    // so iterator "it" is now invalidated
    std::cout << *it << '\n';
    // actually it appears that my compiler will simply move the iterator to
    // the subsequent element, it is not however undefined behavior that results
    // since the next output will always be 4
    ++it; //undefined behavior
    std::cout << *it << '\n';
    return 0;
}