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
*/


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
    return 0;
}
