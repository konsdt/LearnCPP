#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>
/*
16.5 Arrays and loops
loops provide a way to traverse an array without having to explicitly list each element
with templates, arrays and loops we can write code that can operate on a
container of elements regardless of the element type or number of elements in
the container
*/

template <typename T>
T calculateAverage(const std::vector<T>& arr)
{
    std::size_t length { arr.size() };

    T average { 0 };

    for (std::size_t index { 0 }; index < length; ++index)
        average += arr[index];
    average /= static_cast<int>(length);

    return average;
}

template <typename T>
void printArrayElements(const std::vector<T>& arr)
{
    std::size_t length { arr.size() };

    for (std::size_t index {0}; index < length; ++index)
        std::cout << arr[index] << " ";
    std::cout << '\n';
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidNumber() 
{
    int num {};
    do 
    {
        std::cout << "Enter an integer between 1 and 9: ";
        std::cin >> num;

        // Check for failed extraction
        if (!std::cin) // if the previous extraction failed
        {
            if (std::cin.eof()) // if the stream was closed
            {
                exit(0); // shut down the program now
            }

            // let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input

            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input        
        }
    } while (num < 1 || num > 9);
    
    return num;
}

template <typename T>
int findIndex(const std::vector<T>& arr, T value)
{
    std::size_t length { arr.size() };
    for (std::size_t index {0}; index < length; ++index)
    {
        if (arr[index] == value)
            return static_cast<int>(index);
    }
    return -1;
}   


template <typename T>
T findMax(const std::vector<T>& arr)
{
    std::size_t length { arr.size() };
    T max {arr[0]};
    for (std::size_t index {1}; index < length; ++index)
    {
        if (arr[index] > max)
            max = arr[index];
    }
    return max;
}

void FizzBuzz(int iterations) 
{
    const std::vector<int> divisors { 3, 5, 7, 11, 13, 17, 19 };
    std::size_t length {divisors.size()};
    const std::vector<std::string_view> words {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    assert(std::size(divisors) == std::size(words) && "fizzbuss: array sizes dont match");
    
    for (int i {1}; i < iterations; ++i)
    {
        bool dividable {false};
        for (std::size_t j {0}; j < length; ++j)
        {
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                dividable = true;
            }
        }
        if  (!dividable)
        {
            std::cout << i;
        }
        std::cout << '\n';
    }    
        
}
    



int main() 
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The class average is: " << calculateAverage(testScore) << '\n';

    std::vector class1 { 93.2, 88.6, 64.2, 81.0 };
    std::cout << "The class average is: " << calculateAverage(class1) << '\n';
    printArrayElements(class1);
    printArrayElements(testScore);

    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    int num {getValidNumber()};
    printArrayElements(arr);

    int index {findIndex(arr, num)};
    if (index != -1)
    {
        std::cout << "The number " << num << " has index " << index << '\n';
    } else {
        std::cout << "The number " << num << " was not found" << '\n';
    }

    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92


    FizzBuzz(21);
    return 0;
}
