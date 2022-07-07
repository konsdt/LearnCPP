#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter any integer: ";
    int number{};
    std::cin >> number;
    std::cout << "\n";
    return number;

}

void writeAnswer(int number)
{
    std::cout << "The sum of both integers is: " << number << "\n";
}


