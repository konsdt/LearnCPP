#include<iostream>


/*
11.10 C-style string symbolic constants

c-style strings can also be initialized using string literals by writing something
like:
const char* name { "Alex" };
the compiler handles this by putting it somewhere in read only memory and since string
literals can not be altered it has to be const.
Also they have static duration rather than dynamic duration, they will be accessible
until the end of the program even if they go out of scope
*/


int main() 
{

    int nArray[5] { 9, 7, 5, 3, 1 };
    char cArray[] { "Hello!" };
    const char* name { "Alex" };

    std::cout << nArray << '\n'; //nArray will decay to type int*
    std::cout << cArray << '\n'; //cArray will decay to type char*
    std::cout << name << '\n';   // name already is type char*

    /*
    std::cout makes some assumptions about the stuff you want to put out
    if a non-char pointer is passed it will simply print the contents of the pointer
    which means it will print the memory address
    if a char* or const char* is passed it assumes you want to print a string and
    will print the value which is being pointed at, if you force it to print a memory
    address it will try to implicitly convert the integer memory address into type char
    which leads to undefined behavior as demonstrated below
    */
    char c { 'Q' };
    std::cout << &c << '\n';
    return 0;
}