#include <iostream>


// 11.5 Multidimensional Arrays
// The elements of an array can be any data type including arrays, such an array
// is called a multidimensional array
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
    return 0;
}
