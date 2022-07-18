#include <iostream>



double getFloat()
{
    double number {};
    std::cout << "Enter a floating point number: ";
    std::cin >> number;
    return number;
}

char getOperator()
{
    std::cout << "Enter one of the following mathematical symbols:\n" 
        << "+, -, * or /." << '\n';
    char moperator {};
    std::cin >> moperator;
    return moperator;
}

double calculate(const double number1, const double number2, const char moperator)
{
    if (moperator == '+')
        return number1 + number2;
    else if (moperator == '-')
        return number1 - number2;
    else if (moperator == '*')
        return number1 * number2;
    else if (moperator == '/')
        return number1 / number2;
    else
        return "Not an operator";
}


int main()
{
    const double number1{getFloat()};
    const double number2{getFloat()};
    const char moperator{getOperator()};
    const double result{calculate(number1, number2, moperator)};

    if (result == "Not an operator")
        std::cout << " \n";
    else
        std::cout << result;
    return 0;
}
