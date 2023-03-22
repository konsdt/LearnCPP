#include<iostream>
#include<vector>

/*
11.17 An introduction to std::vector
std::array is standard library analogon to build in fixed arrays
std::vector is analogon to dynamic arrays which makes it one of the most useful
and versatile tools to have in a c++ toolkit

std::vector handles its own memory management, thus arrays can be created that
have their length set at run-time, without having to manually allocate memory
space and delete it again
*/

void printLength( const std::vector<int>& v)
{
    std::cout << "The length is: " << v.size() << '\n';
}



int main()
{
    std::vector<int> v;
    std::vector<int> v2 { 9, 7, 5, 3, 1};

    //since c++17 the type can also be omitted:
    std::vector v3 { 9, 7, 5, 3 ,1 };
    // it can also be accessed with not bound checking brackets or
    // bound checking .at() operators, requesting an element out of bounds
    // will never make std::vector resize
    // values can be assigned to a vector using an intitiliazer list
    v = { 3, 2, 1 }; //size of vector is now 3
    v = { 9, 7, 5, 3, 1 }; //vector will self-resize to size 5

    // vectors will self deallocate of the vector variable goes out of scope
    // vectors also remeber their length, and can therefore be asked it by using
    // .size() function
    printLength(v);

    std::vector<int> empty {};
    printLength(empty);
    
    //resizing a vector is very simple by just calling the resize function, new elements
    // are initialized to default value of the type, they can also be resized to be
    // smaller

    v.resize(3);

    for (int i : v)
        std::cout << i << " ";
    std::cout << '\n';

    v.resize(5);
    for (int i : v)
        std::cout << i << " ";
    std::cout << '\n';

    // resizing a vector is computationally very expensive, therfore one should
    // avoid to do that whenever possible
    // if a vector with a certain size is needed one can use parantehsis initialization
    // to achieve that

    std::vector<int> v5(5); // vector with 5 elements that are all 0 
    //bracket initilization would have resulted in a vector with 1 element which is 5
    // std::Vectors of type bool also come with a neet little trick that happens
    // behind the scenes: 8 bools are compacted into 1 byte
    // therefroe saving memory, for the user there is no change in how to 
    // use std::vector for the boolean type

    // one should use std::vector in most cases when a dynamic array is required!
    
    return 0;
}

