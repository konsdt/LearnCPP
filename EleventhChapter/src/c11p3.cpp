#include <iostream>
#include <iterator>
#include <limits>

// 11.3 Arrays and Loops
// it is possible to use a loop to iterate through the array
// loops are typically used with arrays to do one of three things:
// 1. Calculate a value (e.g. average value, total value)
// 2. Search for a value (e.g. highest value, lowest value)
// 3. Reorganize the array (e.g. ascending order, descending order)
//
// Off by one errors are pretty dangerous in this context, since we need to make
// sure that in every loop we do iterate exactly as many times as the array has
// variables

int main()
{
    
    // scores are 0 (worst) to 100 (best)
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents { static_cast<int>(std::size(scores)) };
    
    // Question 3

    int maxIndex { 0 };

    for (int student{ 0 }; student < numStudents; ++student)
    {
        if (scores[student] > scores[maxIndex])
        {
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << scores[maxIndex] << "\n";

    //Question 1

    constexpr int array[] { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int numVariables { static_cast<int>(std::size(array)) };

    for (int variable { 0 }; variable < numVariables; ++variable)
    {
        std::cout << array[variable] << " ";
    }
    std::cout << "\n";

    //Question 2
    
    bool invalid { true };
    int userInput {};
    
    while (invalid)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> userInput;
        
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }

        if (userInput < 1 || userInput > 9)
            continue;
        else
            invalid = false;
    }    

    for (int index { 0 }; index < numVariables; ++index)
    {
        if (array[index] == userInput)
        {
            std::cout << "The number " << userInput << " has Index " << index;
            break;
        }
    }
    return 0;
}
