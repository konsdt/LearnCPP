#include <iostream>

#define PROJECT_NAME "DataTypes"

// 4.1 fundamental data types
// Computers have RAM that is available for programs
// smallest unit of memory: "binary digit" or "bit" can either be 0 or 1
// memory is organized in sequential units calles "memory addresses"
// this allows to find content of memory at a specific location
// each memory address holds one byte of data, one byte contains 8 bit
// older machines might have differently sized bytes (anywhere from 1-48)
// Therefore in C++ one usually works with byte sized data
// 
// all data is stored in the form of bits, therefore "data types" are used to
// tell the compiler how to interpret certain memory in a specific way
// C++ comes with "fundamental data types" (aliases: "basic types", "primitve
// types", "built-in types")
//
// In C++ strings are not a fundamental type, they are a compound type
// but they are very straight forward and extremely usefull
// _t suffix means it is most likely a type, but this is not a consistent 
// naming scheme (int)
//
// 4.2 Void
// the void type means "no type"
// used in two cases: 
// 1. function does not return anything
// 2. deprecated function which does not take any arguments
// Best practice today is instead: give empty argument list in definition
// e.g. : int getValue();
// 3. More advanced use that has not been covered yet: void pointers...
//
// 4.3 Object sizes and sizeof operator:
// most objects take up more space than 1 byte, like 2, 4, 8 or even more
// consecutive memory addresses
// when accessing a variable the compiler bases the amount of bytes to retrieve
// on the type of the variable
// An object that consists from n bits can hold 2^n different values
// -> the size of an object puts a limit on the amount of unique values it is 
// able to store
// Dont focus to much on optimizing your code for needing the least amount of
// memory, but rather write maintainable code. Only optimize where its benefit
// is substantive.
// The size of a given data type is dependent on the compiler and/or the computer
// architecture, only a minimum size is guaranteed for every data type:
//
// boolean      bool         |       1 byte
//              char         |       1 byte
//              wchar_t      |       1 byte
//              char16_t     |       2 bytes
//              char32_t     |       4 bytes
// integer      short        |       2 bytes
//              int          |       2 bytes
//              long         |       4 bytes
//              long long    |       8 bytes
// floating p.  float        |       4 bytes
//              double       |       8 bytes
//              long double  |       8 bytes

// Best practice: for maximum compatibility one should not assume that variables
// are larger than the specified minimum size.
//
// To determine the data size on a particular machine the sizeof operator can be 
// used. It takes either a type or a variable and returns its size in bytes


// 4.4 Signed integers:
// integral type that can represent positive and negative whole numbers
// The key difference between the different integer types is that they have
// varying memory sizes, the larger integers can hold bigger numbers
// by default integers are signed, meaning there sign is stored as part of the
// number (using a single sign bit) 
// defining the four types of signed integers:
// Best practice: do not use int suffix or signed prefix to define integer 
// variables.
// An n-bit signend variable has a range of -(2^(n-1)) to  2^(n-1)-1
// Integer oveflow occurs if one trys to assign an integer to a integer type 
// variable that lays outside the variables range
// this leads to undefined behavior!! Information is lost!!
//
// Integer division:
// C++ always produces an integer as a result of integer dividsion e.g. 8/5 = 1
// The fractional part is always dropped! If this is the desired result it is
// safe to use since the result is predictable.
//
// 4.5 Unsigned integers, and why to avoid them
// can only hold non negative integers
// Overflow: C++ says there can be no overflow for unsigned integers, this is because
// if an integer outside the range is assigned to an unsigned integer variable
// it will be devided by the number that is one larger than the maximum of the 
// variables range. Only the modular is kept -> 280 to 1 byte variable
// , max of 1 byte variable is 2^n - 1:
// 255 -> divide 280 by 256 and keep remainder-> 24 is kept and assigned to the
// variable this is called wrap around, wrap around works in both directions 
// this means in this example -1 would be 255
// Best Practice: Favor signed numbers over unsigned numbers for holding
// quantities and mathematical operations. Avoid mixing unsigned and signed numbers.
// When should they be used?:
// 1. useful for bit manipulation and well defined wrap around behavior
// 2. sometimes unavoidable e.g. array indexing
// 3. emebeded system with imited processor/memory capabilities for performance
// reasons more accepted


// 4.6 fixed width integers and size_t
// prefer "int" when the size of the integer does not matter (majority)
// prefer std::int#_t when storing a quantity that needs a guaranteed range
// prefer std::uint#_t when doing bit manipulation or where well defined wrap
// around behavior is required
// Avoid:
//  - 8bit fixed integers
//  - unsigned types for holding quantities
//  - fast and leas fixed width types
//  - any compiler specific fixed widths
// #include <cstddef> // std::size_t
// size_t is the type of the integer value that is returned by the sizeof() function
// by definition any object that is larger than the largest number size_t can 
// hold is considered ill-formed and will cause a compiler error
// In practice the real limit comes more often from the available RAM
//
//
// 4.7 Scientific notation - duh
// 12000 = 1.2000 * 10^4 = 1.2000e4
// 0.000401 = 4.01 * 10^-4 = 4.01e-4
//
//
// 4.8 Floating point numbers
// there are three different floating point data types: float, doubel, long double
// Best practice: Always make sure the type of your literals match the type of
// the variables they're being assigned to or used to initialize. Otherwise an
// unnecessary conversion will result, possibly with a loss of precision.
// The precision of a floating point number defines how many significant digits
// it can represent without information loss.
// std::cout will print floats with a standard precision of 6
// output manipulators can be used to alter how outputted data is printed
#include <iomanip> // header for output manipulators
// Best practice: Favor double over float because the lack of a floats precision
// will often lead to inaccuracies.
// Rounding errors occur all the time even with simple numbers like 0.1
// They are the rule not the exception, thus never assume your floating point
// numbers are correct
// mathematical operations increase rounding errors!
// There are two special categories of floating point numbers, these are only
// available if the format IEEE 754 is used for floating point numbers
// -> best practice: avoid division by zero!
//




int main() 
{
    //shoow nan's and inf's
    double zero{ 0.0 };
    double posinf { 5.0 / zero };
    std::cout << posinf << "\n";

    double neginf { -5.0 / zero };
    std::cout << neginf << "\n";

    double nan {zero / zero };
    std::cout << nan << "\n";

    // default precision of std:cout
    std::cout << "Default precision of std::cout";
    std::cout << 9.87654321 << "\n";
    std::cout << 987.654321 << "\n";
    std::cout << 987654.321 << "\n";
    std::cout << 9876543.21 << "\n";
    std::cout << 0.0000987654321 << "\n";

    // use output manipulators 
    std::cout << std::setprecision(16);
    // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333333f << "\n"; 
    // no suffix means double
    std::cout << 3.33333333333333333333333333333333333333333 << "\n";


    //wrap around examples: short has 2 byte -> largest possible number: 65535
    unsigned short x{ 65535 };
    std::cout << "x was: " << x << "\n";
    x = 65536;
    std::cout << "x is: " << x << "\n";
    x = 65537;
    std::cout << "x is: " << x << "\n";
    
    unsigned short y{ 0 };
    std::cout << "x was: " << y << "\n";
    y = -1;
    std::cout << "x is: " << y << "\n";
    y = -2;
    std::cout << "x is: " << y << "\n";


    // best practice integer definitions:
    short s{ };
    int i{ };
    long l{ };
    long long ll{ };
    

    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
    return 0;
}
