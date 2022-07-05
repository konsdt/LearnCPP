#include <iostream>

int getInteger()
{
    std::cout << "Enter any integer: ";
    int x{};
    std::cin >> x;
    return x;
}
