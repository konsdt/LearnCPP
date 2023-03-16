#include<iostream>
#include<iterator>
/*
11.9 Pointer arithemetic and array indexing
you can perform integer addition and substraction operations on pointers
ptr + 1 returns the pointer to the next element in memory that has the same type
as ptr, likewise acts ptr - 1



Using a pointer to iterate through an array
usually rather a subscript would be used

*/

bool isVowel(char ch)
{
    switch (ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
        default:
            return false;
    }
}
// Quiz time, but alternative is: std::find which does the same and should
// be preferred instead of writing your own function
int* findValue(int* first, int* last, int value)
{
    for (int* ptr {first}; ptr != last; ++ptr)
    {
        if (*ptr == value)
        {
            return ptr;
        }
    }

    return last;
}



int main() 
{
    int value {7};
    int* ptr { &value };

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';
    std::cout << ptr + 4 << '\n';
    // because an int is 4 bytes each printed address differs by 4 bytes

    // arrays are laid out seqentially in memory:
    int array []{ 9, 7, 5, 3, 1 };

    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';

    //iterate through array using a ptr arithmetic:
    char name[]{ "Mollie" };
    int arrayLength{ static_cast<int>(std::size(name)) };
    int numVowels{ 0 };

    for (char* ptr {name}; ptr != (name + arrayLength); ++ptr)
    {
        if (isVowel(*ptr))
        {
            ++numVowels;
        }
    }

    //counting elements that fullfill a certain condition is so common that
    //the algortihm library offers std::count_if which counts elments that fullfill
    //a certain condition:

    auto numVowels2 { std::count_if( std::begin(name), std::end(name), isVowel) };

    //std::begin returns an iterator(pointer) to the first element while std::end
    //returns an iterator to the element that would be one after the last

    std::cout << std::end(name) << "\n";

    std::cout << name << " has " << numVowels << " vowels.\n" << numVowels2 << "\n";
    /*
    Intersting weird properties of CPP: xD
    arr[2]
    // same as
    *(arr + 2)
    // same as
    *(2 + arr)
    // same as
    2[arr]
    */
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    //search for the first element with value 20:
    int* found { findValue(std::begin(arr), std::end(arr), 1) };


    if (found != std::end(arr))
    {
     std::cout << *found << '\n';
    }

    return 0;
}