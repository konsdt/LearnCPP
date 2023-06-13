#include<iostream>
#include<functional>
    
char get_mathematical_operator() {
    char math_operator {};
    do {
        std::cout << "Please enter one of the mathematical operations: (‘+’, ‘-‘, ‘*’, ‘/’)";
        std::cin >> math_operator;
    }
    while ((math_operator != '+' and math_operator != '-' and math_operator != '/' and math_operator != '*'));
    return math_operator;
}   

int get_integer() {
    int number {};
    std::cout << "Please enter an integer number:" << '\n';
    std::cin >> number;
    return number;
} 

int add(int number1, int number2) {
    return number1 + number2;
}

int subtract(int number1, int number2) {
    return number1 - number2;
}

int multiply(int number1, int number2) {
    return number1 * number2;
}

int divide(int number1, int number2) {
    return number1 / number2;
}

using ArithmeticFunction = std::function<int(int,int)>;


ArithmeticFunction getArithmeticFunction(char op) {
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &divide;
    }
    return nullptr;
}
int main() {

    
    int number1 {get_integer()};
    char op {get_mathematical_operator()};
    int number2 {get_integer()};
    
    ArithmeticFunction operation {getArithmeticFunction(op)};
    std::cout << number1 << op << number2 << '\n';
    std::cout << operation(number1, number2);
    return 0;
}