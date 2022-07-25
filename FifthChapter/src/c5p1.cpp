#include <iostream>
#include <cmath>
#include <cassert> // for assert function

#define PROJECT_NAME "Operators"

// 5.1 Operator precedence and associativity
// "Precedence" defines order in which operators are evaluated(e.g. math)
// "associativity" tells the compiler in which order to evaluate adjacent 
// operators if their precedence has the same level
// "parenthesization" change order of execution () have one of the highest 
// precedence level
// /Best Practice/ Use parantheses to make it clear how a non-trivial expression
// should evaluate. (Even if they are technically unnecessary.)
// /Best Practice/
// Outside of operator precendence and associativity rules, assuem that the parts
// of an expression could evaluate in any order. Ensure that the expressions you
// write are not dependent on the order of evaluation ot those parts.
// 5.2 Arithmetic operators
// "int and float division": if both operands are ints any fraction that results
// from division is simply dropped! Use static cast to double to avoid it
// Assignment operations work: x = x + 4 <=> x += 4.
// 5.3 Modulus and Exponentiation
// Modulus is the remainder operator, it is sign sensitive
// Exponentiation is included in the <cmath> header
// pow() parameters and return value are doubles (due to rounding errors the
// result may not be precise even if integers or whole numbers are passed)
// For integer expontiation one should use your own function!
// See implementation below

// uses non straigth forward exponentiation by squaring??.. can not understand
// it yet
std::int64_t powint(int base, int exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");
    
    std::int64_t result { 1 };
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

// 5.4 Increment and decrement oparators & side effects
// Increment: add one
// Decrement: substract one
// ++x increment x, then return x
// --x decrement x, then return x
// x++ copy x increment copy, return original x
// x-- copy x, decrement copy, return original x
// /Best practice/: Strongly favor the prefix version of the increment 
// and decrement operators as the are generally more performant, and you are 
// less likely to run into strange issues with them.
// "Side effects": expression has side effect if it does anything that persists
// beyond the life of the function/expression itself
// Can lead to unexpected behavior: e.g.: x = 5 add(x, ++x) 11 or 12? compiler
// can execute in any order
// /Warning/: Do not use variable that has side effect applied more than once
// in a given statement!
// 


int getInt()
{
    int number{};
    std::cout << "Enter an integer: ";
    std::cin >> number;
    return number;
}

bool isEven(int number) 
{
    if ((number % 2) == 0)
        return 1;
    else
        return 0;

}
    // note: exponent must be non negative!
int main() {
    double x{ std::pow(3.0, 4.0) }; //3 to the power of 4
    int number{ getInt() };
    if (isEven( number ))
        std::cout << number << " is even." << '\n';
    else
        std::cout << number << " is odd." << '\n';


    std::cout << powint(7, 12) << '\n'; // 7 to the 12th power
    
    int a { 5 };
    int b = a++;
    
    std::cout << "a gets incremented: " << a << " and b is copy of a " << b << '\n';

    return 0;   
}

