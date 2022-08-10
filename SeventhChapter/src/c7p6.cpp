#include<iostream>
#include<cmath>
// 7.6 Goto statements
// an unconditional jump is implemented by a goto statement, and the spot to jump
// to is identified through use of a statement label
// they have "function scope": this is a third kind of scope which means they
// are visible throughout the entire function even before the point of definition
// thus goto statements can also jump forward
// /Best practice/: Avoid goto statements (unless the alternatives are significantly
// worse for code readability)
// Reason: they easily lead to spaghetti code
//
// 7.7 Intro to loop and while statements
// "While statements": is evaluated while its condition is evaluated to true
// and the process is repeated until the condition no longer evaluates to true
// /Best practice/: For intentional infinite loops favor "while (true)".
// /Best practice/: Loop variables should be of type (signed) int.
// To do somethin every n-th iteration a conditional statement using the modulo 
// operator can be used: e.g.: if (count % 2 == 0) do sth every 2nd iteration
//
// 7.8 Do while statements
// Is a looping construct just like the while loop with the exception, that the
// statement always executes at least once
//
// do
//      statement;
// while (condition);
//
// /Best Practice/: Favor while loops over do-while when given an equal choice.
//
// 7.9 For statements
// For loop is preferred if there is an obvious loop variable
// Syntax:
//
// for (init-statement; condition; end-expression)
//  statement
// e.g. of a function that can calculate integer exponents
int pow(int base, int exponent)
{
    int total{ 1 };

    for (int count{ 0 }; count < exponent; ++count)
        total *= base;

    return total;
}
// it is possible to omit init-statement and end-statement, this is e.g. done when
// there already is a variable that we want to loop over
// for loops can be used with multiple counter by usage of the comma operator
// /Best Practice/: Defining multiple variables and using the comma seperator is
// acceptable inside a for statement.
// For loops can also be nested
// /Best Practice/: Prefer for loops over while loops when there is an obvious loop
// variable.
// Prefer while loops over for loops when there is no obvious loop variable.
//
int sumTo(int value)
{
    int sum{0};
    for (int iii{1}; iii <= value; ++iii)
        sum += iii;
    return sum;
}


int main()
{
    double x{};
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
        goto tryAgain; // this is the goto statement

    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
    // while loop
    int count{1};
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!";
    
    // Print all letters and there ascii codes
    int letter {97};
    while (letter <= 122)
    {   
        std::cout << "ASCII Code: ";
        if (letter < 100)
            std::cout << '0';
        std:: cout << letter << ' ' << "Letter: ";
        std::cout << static_cast<char>(letter) << '\n';
        ++letter;
        
    }

    // invert the nested loop:
    
    int outtercount { 5 };
    while (outtercount >= 1)
    {
        int innercount { outtercount };
        while (innercount >= 1)
        {
            std::cout << innercount << ' ';
            --innercount;
        }
        std::cout << '\n';
        --outtercount;
        
    }


    int outtercount2 { 1 };
    while (outtercount2 <= 5)
    {
        int spacecounter{ 12 - 2 * outtercount2};
        while (spacecounter > 1)
        {
            std::cout << ' ';
            --spacecounter;
        }

        int innercount2 { outtercount2 };
        while (innercount2 >= 1)
        {   
            
            std::cout << innercount2 << ' ';
            --innercount2;
        }
        std::cout << '\n';
        ++outtercount2;
    }
  
    // FOR LOOP
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << count << ' ';
    
    // for loop with multiple counter
    for (int x { 0 }, y { 9 }; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    for (char c{'a'}; c <= 'e'; ++c)
    {
        std::cout <<c;

        for (int i{0}; i < 3; ++i)
            std::cout << i;
        std::cout << '\n';
    }
    // For loop quiz time
    for (int number{ 0 }; number <= 20; ++number)
        std::cout << number << '\n';
    int value{};
    std::cout  << "Enter any integer: ";
    std::cin >> value;
    std::cout << sumTo(value);


    return 0;
}
