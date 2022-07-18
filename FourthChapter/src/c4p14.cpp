#include <iostream>
#include <string> // allows use of std::string
#include <string_view>

// 4.17 std::string
// Double quoted strings "" we call "C-style strings" (inherited from C)
// C++ introducd two new string types that are much easier and safer to work with
// "std::string" and "std::string_view"(C++17)
// to read a full line of input into a string use std::getline()
// needs two arguments, the first is std::cin and the second is the string 
// variable
// std::ws is an input manipulator that instructs to ignore any leading whitespace
// before extractionr
// Always use it together with std::getline()
// String length:
// length() is a member function of std::string and can therefore be called by:
// name.length()
// Avoid passing std::string as a value via a parameter since every time a copy is made
// and copies of std::string are extremely expensive, use std::string_view for
// this purpose.
//
//4.18 std::string_view
// provides read only access to the strin and avoids making copies when passing
// string values...
// Best practice: Prefer std::string_view over std::string when you need a read
// only string, especially for function parameters.
//

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s {"Hello world!\n"};
    printSV(s);





    std::cout << "Enter your full name: ";
    std::string name {}; // empty string
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
    
    std::cout << "Enter your age: ";
    std::string age {};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age
    
    std::cout << "Your name is " << name << " and your age is " << age << '\n';
    std::cout << "Your age + length of name is: " << static_cast<int>(std::stoi(age)) +
        static_cast<int>(name.length()) << '\n';
    // I dont know if those functions return unssigned or signed integers, and
    // therefore I cast them to unssigned representations in order to not mix
    // signed and unsigned integers


    std::cout << "Enter some word: ";
    std::string testLength {};
    std::getline(std::cin >> std::ws, testLength);
    std::cout << "The length of the entered word is: " << testLength.length() << '\n';

    return 0;
}
