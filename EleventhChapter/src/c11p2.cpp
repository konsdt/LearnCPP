#include <iostream>
#include <iterator>

// 11.2 Arrays (Part II)
// Arrays can be initialized with an initializer list
// "best Practice": Explicitly Initialize your arrays (even when the element type
// is self-initializing)
// if a fixed array is initialized with an initializer list one can omit the lenght
// since the compiler can deduce the fixed lenght from the quantity of elements
// in the initial list
// "Arrays and enums":
// arrays have a big documentation problem meaning the integer indices do not 
// provide any information about the meaning of the index
// this can be solved by wsetting up an enumeration where one enumerator maps to
// each of the possible array like indices
// this trick ofc only works if the enum values are not set manually
// it also only works with enums and not with scoped enums since they do not 
// automatically convert to integers. 
// One could solve this by using a static_cast<int> but this is a little painfull
// to do every time therefore it might be better to use a standard enum inside a
// namespace
//
// Passing arrays to functions
// Arrays are not copied when passed since this can be very expensive, therefore
// the actual array is passed to the function, therefore functions can directly
// change the values of an array
// if one wants to ensure that a function can not modify a passed array one can
// make the array constant, this will lead to an compile error whenever the function
// trys to change the array
//
// Determining the length of an array: use std::size() from the iterator header
// due to the way arrays are passed in c++ this will not work on arrays that 
// have been passed to a function
// std::size was only introduced with c++17 and will work on arrays and vectors
// before that one has to use the std::sizeof operator which sadly is not as easy 
// to use:
// sizeof can be used on arrays and it will return the total size of the array
// (array multiplied by element size)


// IMPORTANT: Indexing out of range: C++ does not do any checks whether the
// given index does make sense for the respective array!!!!!
// Therefore if we assign a value to an array with an out of range index this will
// lead to undefined behavior since c++ simply assigns the value to the place in
// memory where it would belong if the array had the required lenght, therefore
// some other used value in memory might be overridden accidentally. Also negative
// indexes will not throw any errors
// "Rule": When using arrays, ensure that your indices are valid for the
// range of your array!!!
//
void passValue(int value)
{
    value = 99;
}

void passArray(int prime[5])
{
    prime[0] = 11;
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}


namespace StudentNames
{
    enum StudentNames
    {
        kenny,
        kyle,
        stan,
        butters,
        cartman,
        max_students,
    };
}

// Quiztime
double highTempYearPerDay[365]{};

namespace Animals
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_number_animals,
    };
}

int main()
{
    
    int numberOfLegs[Animals::max_number_animals] { 2, 4, 4, 4, 2, 0};
    
    std::cout << "An elephant has " << numberOfLegs[Animals::elephant] << " legs.\n";

    int prime[5]{ 2, 3, 5, 7, 11 }; // use initializer list to init array
    
    // this will print the arrays address
    std::cout << prime << "\n";

    // automatically deduce array length
    int array[]{ 1, 2, 3, 4, 5 };
    // by using an enum this provides context to the array indices
    int testScores[StudentNames::max_students]{};
    testScores[StudentNames::stan] = 76;

    std::cout << testScores[StudentNames::stan] << "\n";

    //passing arrays to functions

    int value { 1 };

    std::cout << "before passValue: " << value << "\n";
    passValue(value);
    std::cout << "after passValue: " << value << "\n";
    
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << 
        prime[2] << " " << prime[3] << " " << prime[4] << "\n";
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << 
        prime[2] << " " << prime[3] << " " << prime[4] << "\n";

    
    std::cout << std::size(array) << "\n";
    std::cout << sizeof(array) << "\n"; // will print thje size of the array multiplied by the size of an int
    std::cout << sizeof(int) << "\n"; // 
    std::cout << sizeof(array) / sizeof(array[0]) << "\n";
    

    return 0;
}
