#include <iostream>
#include <vector>

/*
16.4 Passing and returning std::vector, and an introduction to move semantics
To avoid making expensive copies (passing by value) vectors are typically
passed by (const) references.
The element type must be specified in the function parameter explicitly

If we want to pass arrays with a different element type to the same function
we need to find other solutions:
Class Template Argument Deduction (CTAD) does not work for this purpose 
Therefore we need to use template parameters


If we need to assert on array length a better option is to avoid using std::vector.
Here using a type that supports "constexpr" (e.g. std::array) is probably a better
choice, as you can "static_assert" on the length of constexpr array.

It is okay to return std::vector by value ?!?!?!?!??!

This is because of "move semantics": instead of making a copy and then destroying
the original, we just move the data from the object that is about to be destroyed
to the one that lives on. This is way faster than copying and will be used when
all of the following is true:
 - the type supports move semantics
 - we are initializing or assigning to an object using an rvalue object of the same type
Sadly not many types support moving (only std::vector and std::string)
This makes returning these types extremely cheap.

*/

template <typename T>
void passByRef(const std::vector<T>& arr)
{
    std::cout << arr[0] << '\n';
}



/*
also possible:
template <typename T>
void passByRef(const T& arr)
{
    std::cout << arr[0] << '\n';
}

Or with c++20 the abbreviated function template via the auto parameter:
void passByRef(const auto& arr)
{
    std::cout << arr[0] << '\n';
}
*/

void printElement(const auto& v, int index)
{
    if (index < static_cast<int>(v.size()) & index >= 0) 
    {
        std::cout << v[index] << '\n'; 
    } else
    {
        std::cout << "Error: index " << index << " is out of bounds. \n";
    }

}

std::vector<int> generate() 
{
    //We're intentionally using a named object here so mandatory copy elision 
    //does not apply
    std::vector arr1 { 1, 2, 3, 4, 5}; // copies { 1, 2, 3, 4, 5 } into arr1
    return arr1;
}

int main()
{
    std::vector primes { 2, 3, 5, 7, 11 }; //uses CTAD for type deduction
    std::vector dbl { 1.1, 2.2, 3.3 }; //uses CTAD for type deduction

    passByRef(primes);
    passByRef(dbl);

    std::vector arr1 { 1, 2, 3, 4, 5 }; // copies { 1, 2, 3, 4, 5 } into arr1
    std::vector arr2 { arr1 }; // copies arr1 into arr2

    arr1[0] = 6; // We can continue to use arr1
    arr2[0] = 7; // and we can continue to use arr2

    std::cout << arr1[0] << arr2[0] << '\n';

    std::vector arr3 { generate() }; // the return value of generate() dies at
    // the end of the expression

    // There is no way to use the return value of generate() here 
    arr3[0] = 7; // we only have access to arr3
    std::cout << arr3[0] << '\n';

    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);


    return 0;
}