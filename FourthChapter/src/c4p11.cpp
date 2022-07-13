#include <iostream>

// 4.11 Chars
// char data type can hold a "character": single letter, number, symbol or white-
// space.
// integral type (underlying value is stored as an integer)
// Integer stored is interpreted via the american standard code for information
// interchange. (ASCII) 0-127 integers that represent certain characters
// Chars 0-31 are unprintable characters (mostly obsolete)
// 32-127 are printable characters

// if one wants to use more then onbe character, one has to use a string
// this is a collection of sequential characters and can therefore hold multiple
// symbols
//
// char always has 1 byte in size
//
// Escape sequences are characters that have a special meaning and start with
// a backslash '\'
// '\n' newline
// '\'' prints a single quote
// '\"' prints a double quote
// '\\' prints a backslash
// Best practice: Put stand-alone charcters in single quotes and! This is important
// and helps the compiler optimize more effectively.
// 

int main()
{
    // chars can be defined via there ascii code 
    char ch1{ 97 };
    // or via the actual character (preferred):
    char ch2{ 'a' }; // apparently here I definitely need to use only singular
                     // high commata '' not ""... weird

    std::cout << ch1 << ch2 << "\n";

    return 0;
}
