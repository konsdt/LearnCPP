#include <iostream>

// 4.10 conditional statements

int main() 
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
    // chained if statements
    if (x > 0)
        std::cout << "The value is positive.\n";
    else if (x < 0)
        std::cout << "The value is negative.\n";
    else
        std::cout << "The value is zero.\n";

    // non-boolean conditionals:
    if (4)
        std::cout << "4 and any other non-zero values evaluate " 
                  <<  "to true, only 0 evaluates to false.";
    return 0;
}
