#include <iostream>

// 7.1 Control flow introduction
// by default the code execution begins at top of main, executes the contained
// statements sequentially and then terminates at the end of main
// this is called the "execution path" or just "path"
// "straight line program":
// these kind of programs take the same "path" every time they run
// this is not want is wanted most of the time 
// -> "control flow statements":
// categories:
// * conditional statements: if else etc.
// * jumps: start executing statements at some other locations
// * function calls: are jumps to some other location and back
// * loops: repeat some statements x times
// * halts: quit running the program
// * exceptions: designed for error handling
//
// 7.2 If statements and blocks
// under this condition do this or do that
// /Best practice/: simply always use blocks, even if you just want to make a
// single statement conditional
// if blocks are not explicitly used, the compiler will set a blokc around the
// first statement that follows the if or else clause
// This matters when defining variables inside the conditional statements
// These have block scope and will therfore be destroyed at the end of the if 
// statement
//
// 7.3 Common if statement problems
// "Nested if statements and the danling else problem":
// else is always matched up with last unpaired if -> always use blocks so you
// avoid mixing up the else with the wrong if statement
// one should whenever possible flatten nested if statements -> restructure the 
// logic in such a way, that all is covered in one if else if and else routine
// "Null statements":
// they do nothing, usually exists when the language demands a statement but the
// programmer does not need one
// dont confuse "==" with "=" in if statements -> this mistake usually will not
// result in a compiler error
//
// 7.4 Switch statement basics
// it is possible to chain several if-else statements together, but this is both
// difficult to read and inefficient since the variable in the condition
// needs to be evaluated every time
// Testing an expression for equality against several different values is very
// common in c++, therefore it provides an alternative way of doing so.
// "switch statement": The switch expression "condition" is evaluated once,
// if its value is equal to one of the values behind one of the cases, the
// statements after the matching case label are executed. If non of the statements
// matches the default is executed.
// /Best practice/: Use a switch statement over if-else chains when there is a 
// choice.
// can only be used with integral types, they are done by using jump tables
// every case label must be unique
// /Best practice/: Place the default label last in a switch block
// Every case needs to be ended with either a return statement (that would directly
// end the entire function, which contains the switch statement)
// or by a "break" statement. The "break" tells the compiler, that we are done
// executing code of the switch statement and resumes executing the function code 
// that comes after.
// /Best Practice/: Each set of statements underneath a case label should end
// with a return or a break statement.
//
// 7.5 Switch fallthrough and scoping
// "fallthrough": leaving out a break or return statement in a set of case label
// statement leads to execution of the code of all the statements followed by
// the case label which matched the case expression (condition)
// We say the execution overflows into the subsequent cases.
// The fallthrough attribute: [[fallthrough]]; tells other programmers, that
// the fallthrough is intentional and required in this case (comes with c++17)
void printDigitName(int x)
{
    switch(x)
    {
        case 1:
            std::cout << "One";
            break;
        case 2:
            std::cout << "Two";
            break;
        case 3:
            std::cout << "Three";
            [[fallthrough]];
        case 4:
            std::cout << "Four";
            break;
        default:
            std::cout << "Unknown";
            return;
    }
    std::cout << ", yay we knew the number." << '\n';
}
// sequential case labels, one can use the logical OR operator to combine
// several tests into one statement, this is possible with cases aswell, by 
// stacking them. This is not considered fallthrough behavior, so we do not
// have to use the attribute here or comment it.

bool isVowel(char c)
{
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

// switch statements, unlike if statements, do not create implicit blocks.
// /Best practice/: If defining variables used in a case statement, do so in 
// a block inside the case! ({})


int calculate(int a, int b, char operation)
{
    switch(operation)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
        default:
            std::cout << operation << " is not a valid" << 
                " mathematical operator. Please choose from the following" 
                << " operations: ['+', '-', '*', '/', '%']" << '\n';
            return 0;
    }
}

int getInteger()
{
    int num{};
    std::cout << "Enter any integer: ";
    std::cin >> num;
    return num;
}

char getOperator()
{
    char operation{};
    std::cout << "Enter a mathematical operator: ";
    std::cin >> operation;
    return operation;
}

int main() 
{
    int x { 9 };
    if (x > 10)
    {
        ; // this is a null statement
    }

    printDigitName(3);

    printDigitName(4);
 
    printDigitName(5);

    if (isVowel('e'))
        std::cout << "Is a vowel";
    
    std::cout << calculate(getInteger(), getInteger(), getOperator());

    return 0;
}
