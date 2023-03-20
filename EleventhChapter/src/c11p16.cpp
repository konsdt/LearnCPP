#include<iostream>
#include<array>
#include<algorithm> // for std::sort



/*
11.16 An introduction to std::array

Passing std::array of different lengths to a function:
With a std::array the elemtn type and array length ar part of the type information
Therfore, when we use a std::array as a function parameter, we have to specify the
element type and array length
This would limit the function to only being able to handle arrays of a certain 
length and type

luckily we have templates:
*/

// print array is a template function:
template <typename T, std::size_t size>
void printArray(const std::array<T, size> myArray)
{
    for (auto element : myArray)
        std::cout << element << " ";
    std::cout << '\n';
}

int main()
{
    std::array<int, 5> myArray { 9, 7, 5, 3, 1 };
    //std::array myArray { 9, 7, 5, 3, 1 }; // possible since c++17
    //c++20 even allows to omit the array length and only specify the type
    // this works with the std::to_array function:
    auto myArray1 { std::to_array<int, 5>({ 9, 7, 5, 3, 1}) };
    auto myArray2 { std::to_array<int>({ 9, 7, 5, 3, 1}) };
    auto myArray3 { std::to_array({ 9.2, 7.3, 5.1, 3.0, 1.9}) };

    // but to_array is more expensive since it copies all elements from a c-style
    // array, and should therfore be avoided when the array is created many times
    // just like for built in arrays the subscript operator does not do any bounds
    // checking, therefore one must also be very careful to not provide an index
    // that is out of bounds

    myArray.at(1) = 6;
    //this .at() operator does runtime bounds checking, therefore it is slower
    // but safer than operator[]

    //size function:
    std::cout << "length: " << myArray.size() << '\n';
    // since std::array does not decay to a pointer when passed to a function the
    // size function will work inside a function that is passed an array
    // size is here the array length and not array length times array type like sizeof() returns
    // "Best practice": Always pass std::array by reference or const reference(read only).

    // std::array can be sorted using std::sort (algortihm header)
    std::sort(myArray.begin(), myArray.end()); // sort array forwards
    // std::sort(myArray.rbegin(), myArray.rend()) //sort the array backwards
    
    for (int element: myArray)
        std::cout << element << " ";
    std::cout << '\n';


    printArray(myArray3);

    return 0;
}