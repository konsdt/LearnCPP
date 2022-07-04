#include <iostream>

// 2.4 Function parameters and arguments
// eg: of functions with different numbers of parameters
// the number of arguments must generally match the number of function parameters
// otherwise the compiler will throw an error

void doPrint() {
    std::cout << "In doPrint().\n";
}


int getValueFromUser() {
    int num{ };
    std::cout << "Enter any integer: ";
    std::cin >> num;
    return num;
}

void printDouble(int num) {
    std::cout << "Double " << num << " is " << num * 2 << "\n";
}
void printValue(int x) {
    std::cout << x << "\n";
}

int add(int x, int y) {
    return x + y;
}

int doubleNumber(int num) 
{
    return 2 * num;
}


int main() {
    int z{ getValueFromUser() };
    printValue(add(23, 19));
    printDouble(z);
    // This works fine aswell:
    printDouble(getValueFromUser());
    return 0;
}
