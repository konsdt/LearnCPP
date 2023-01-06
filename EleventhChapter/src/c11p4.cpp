#include <iostream>
#include <utility> // for std::swap
#include <algorithm> // for std::sort


// 11.4 Sorting an array using selection sort
// Sorting makes searching faster, and sometimes even makes it obsolete
// Swapping elements can be done with std::swap() from the utility header
// sorting arrays is very common in c++ therefore its standard library includes
// a sorting function in the algorithm header


int main()
{
    int x { 2 };
    int y { 4 };
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    std::swap(x, y); // swap the values of x and y
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";

    int array[]{ 30, 50, 20, 10, 40 };
    std::sort(std::begin(array), std::end(array));

    for (int i { 0 }; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << " ";
    
    std::cout << "\n";

    // Selection sort algorithm that sorts from big to small
    
    constexpr int length { static_cast<int>(std::size(array)) };

    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        int biggestIndex{ startIndex };

        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            if (array[currentIndex] > array[biggestIndex])
                biggestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[biggestIndex]);
    }

    for (int index{ 0 }; index < length; ++ index)
        std::cout << array[index] << " ";

    std::cout << "\n";
    
    // Question 3 Bubble sort


    int array1[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    constexpr int length1 { static_cast<int>(std::size(array1)) };

    bool checkSwaps { false }; 
    for (int repeat { 1 }; repeat < length1; ++ repeat)
    {
        for (int startIndex{ 0 }; startIndex < length1 - repeat; ++startIndex)
            {
                if (array1[startIndex] > array1[startIndex + 1])
                {
                    std::swap(array1[startIndex], array1[startIndex + 1]);
                    checkSwaps = true;
                }
            }
        if (!checkSwaps)
        {
            std::cout << "Early termination on bubble iteration: " << repeat << "\n"; 
            break;
        }
    }

    for (int i { 0 }; i < length1; ++i)
        std::cout << array1[i] << " ";
    
    std::cout << "\n";
    return 0;
}
