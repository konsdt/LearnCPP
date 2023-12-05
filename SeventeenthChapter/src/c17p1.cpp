#include <iostream>
#include <array>
#include <vector>


/*
17.1 Introduction to std::array
std::vectro is slightly less performant than fixed sized arrays
std::vector only supports "constexpr" in very limited context
constexpr arrays offer the ability to write code that is more robust and can
be optimized more highly by the compiler
"Best practice:" Use std::array for constexpr arrays, and std::vector for 
non-constexpr arrays.

The length of an array must be a constant expression.

arrays are aggregates, which means they allow direct initialization of there
members and do not have a constructor 

a std::array can be const or constexpr

"Best practice:" Define your std::array as constexpr whenever possible.
If your std::array is not constexpr, consider using std::vector instead.

"Best practice:" Use Class Template Argument Deduction (CTAD) to have the 
compiler deduce the type and length of a std::array from its initializers.

17.2 std::array length and indexing
size is like for vector .size() -> std::size_t, std::size() calls the member function
.size() and std::ssize() returns a signed type -> std::ptrdiff_t
All of them return the length as a constexpr, therefore all outputs can
be transformed to an integer without it being a narrowing conversion

indexing: we can use:
- []operator: no bounds checking
- .at(): runtime bound checking
- std::get: compile time bound checking 
since for compile time bound checking we need the values that are compared
to be constexpr, therefore this does only work with constexpr indices


17.3 Passing and returning std::array
typically pass it by (const) ref
for std::array type information and size are part of the object, thus both
need to be explicitly specified when passing them to a funtion
CTAD sadly does not exist for passing arrays yet, but it works in defining arrays

Returning:
 - by value if:
    * array is not huge
    * The element type is cheap to copy
    * code not used in performance sensitve context
- out parameter: (void functon that receives a non-const ref and can thus modify the array)
- return a std::vector instead: if array is returned by value it most likely
is not a constexpr and therfore one could return it as a std::vector instead
*/

template <typename T, std::size_t N>
void passByRef(const std::array<T, N>& arr)
{
    std::cout << arr[0] << '\n';
}
template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    std::cout << "The array (";
    
    for (std::size_t i {0}; i < N; ++i)
    {
        std::cout << arr[i];
        if (i < N - 1)
             std::cout << ", ";
    }
    std::cout << ") has length " << N << '\n';

}

int main() {
    
    std::array<int, 5> a {}; //Using a literal constant for array length

    std::vector<int> b(5);

    constexpr int len { 8 };
    std::array<int, len> c {}; // Using a constexpr variable

    enum Colors 
    {
        red,
        green,
        blue,
        max_colors
    };
    std::array<int, max_colors> d {}; //Using an enumerator

    std::array<int, 6> fibonacci = { 0, 1, 1, 2, 3, 5 }; // copy init using braced 
    std::array<int, 5> prime { 2, 3, 5, 7, 11 }; // list init using braced list (preferred)

    constexpr std::array<double, 365> dailyHighTemperature {};
    constexpr std::array hello {'h', 'e', 'l', 'l', 'o'}; 

    std::cout << hello[1] << '\n';

    std::cout << hello.at(1) << '\n';

    std::cout << std::get<1>(hello) << '\n';


    passByRef(fibonacci);
    passByRef(prime);

    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
