#include<iostream>
#include<vector>

/*
12.3 std::vector capacity and stack behavior
std::vector is a dynamic array that remembers its length and can be resized as required
std::vector does not only know its lenght but also its capacity, that is how
many elements were allocated in memory
The capacity is at least the length but could be larger (otherwise the elements
at the end of the array would be outside of the allocated memory)

subscript an at() operator are therefore based on array length

Stack behavior with std::vector
can be used as stack with the following three functions:
 * push_back() pushes an element on the stack
 * back() returns the value of the top element on the stack
 * pop_stack() pop_back() pops an element off the stack
 
 When doing this the array will only be resized when needed (capacity would not
 be enough for length)
 this is computationally very expensive and therefore C++ allows to reserve
 a specific capacity for the std::vector object beforehand to discard the need
 for resizing

 Also when we push an element to an array and it needs to be resized for more
 capacity, the compiler actually might increase the capacity more than actually
 required in order for not having to do it again immediately
 By how much it is increased depends on the compiler implementer

 the c++ standard requires that std::vector::resize() grows capacity exponentially
 Therefore most implementations will multiply the current capacity by 1.5 or 2
 
*/


int main() {
    std::vector array { 0, 1, 2 };
    array.resize(5); // set length to 5

    std::cout << "The length is: " << array.size() <<  '\n';
    std::cout << "The capacity is: " << array.capacity() << '\n';
    for (auto element: array)
        std::cout << element << ' ';


    std::vector<int> array1 {};
    array1 = { 0, 1, 2, 3, 4 };
    std::cout << "length: " << array1.size() << " capacity: " << array1.capacity() << '\n';

    array1 = { 9, 8, 7 };
    std::cout << "length: " << array1.size() << " capacity: " << array1.capacity() << '\n';
    return 0;
}