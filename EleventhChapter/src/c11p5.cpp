#include <iostream>
#include <iterator>


// 11.5 Multidimensional Arrays
// The elements of an array can be any data type including arrays, such an array
// is called a multidimensional array
//
// 11.6 C-style strings
// a c-style string is an array of characters that uses a "null terminator" which
// is a special character '\0' used to indicate the end of a string
// that is why they are also called a null terminated string
//
//

int main()
{
    // intitializing 2d array:
    int array[3][5]
    {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 }
    };
    
    // while doing this the left most length specicfication can be ommited
    int array1[][5]
    {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 }
    };

    // Accessing elements in a 2d array
    
    int numRows{ 3 };
    int numCols{ 5 };
    
    for (int row{ 0 }; row < numRows; ++row)
    {
        for (int col{ 0 }; col < numCols; ++col)
        {
            std::cout << array[row][col] << " ";
        }
    }
    std::cout << "\n";

    // arrays can have a lot of dimensions e.g.:
    // 3d array:
    int array2[2][3][4];
    // when dealing with such arrays there is no intuitive way to initialize them
    // in such a case values are usually later assigned in loops
    //
    
    // to initialize a c-style string one simply uses a char array:
    char myString[]{ "string" };
    // c++ automatically adds a null terminator to the length of the array, therfore
    // eventhough there are only 6 letters this is an array with size 7
    //
    // using c-style string with cin:

    char name[255]{};
    std::cout << "Enter your name: ";
    std::cin.getline(name, std::size(name));
    std::cout << "You entered: " << name << "\n";
    // getline will discard everything after the 255 symbol leaving room for 
    // the null terminator, this way one ensures that no undefined behavior happens
    // if the user enters more than 255 characters, whether it might have been
    // accidentally or maliciously
    // The header <cstring> contains loads of functions to manipulate cstyle strings
    // But "Best Practice": Use std::string or std::string_view instead of 
    // c-style strings


    return 0;
}
