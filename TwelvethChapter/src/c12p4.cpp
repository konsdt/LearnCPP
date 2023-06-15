#include<iostream>
#include<vector>


/*
12.4 Recursion
A recursive function is a function that calls itself
recursive functions must include a "recursive termination condition"

This output is due to the way the stack works, the termination criterion
like this does not terminate the function but instead it is resumed when it
is cleared of the stack

A more usefull example:


sumTo(5) called, 5 <= 1 is false, so we return sumTo(4) + 5.
sumTo(4) called, 4 <= 1 is false, so we return sumTo(3) + 4.
sumTo(3) called, 3 <= 1 is false, so we return sumTo(2) + 3.
sumTo(2) called, 2 <= 1 is false, so we return sumTo(1) + 2.
sumTo(1) called, 1 <= 1 is true, so we return 1.  This is the termination condition.

Now while unwinding the stack is where the magic happens:
sumTo(1) returns 1.
sumTo(2) returns sumTo(1) + 2, which is 1 + 2 = 3.
sumTo(3) returns sumTo(2) + 3, which is 3 + 3 = 6.
sumTo(4) returns sumTo(3) + 4, which is 6 + 4 = 10.
sumTo(5) returns sumTo(4) + 5, which is 10 + 5 = 15.
*/
int sumTo(int sumto) {
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an
        // unexpected argument (0 or negative)
        
    if (sumto == 1)
        return 1; // normal base case (termination condition)
    
    return sumTo(sumto - 1) + sumto;

}


/* 
Fibonacci numbers:
appear in many places in nature: spiral shells, fruitlets of a pineapple, pine cone

F(n) = 0 if n = 0
       1 if n = 1
       f(n-1) + f(n-2)
*/

int fibonacci(int n) {
    if (n <= 0) 
        return 0;
    if (n == 1)
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
This in fact is a very uneffieceint implementation since every non base call
of the fibonaccie function results in 2 more calls of the function and so on
therfore this calls the funtion exponentially

To improve the number of calls necessary there are techniques like 

Memoization
This caches the results of expensive funtion calls such that they can be returned
when the function is called again with the same input
*/
int mem_fib(int n) {

    // a static vector is used to cache calculated results
    static std::vector results { 0, 1 };

    // if already calculated then use cached result
    if (n < static_cast<int>(std::size(results)))
        return results[n];
    
    //otherwise calculate
    results.push_back(mem_fib(n - 1) + mem_fib(n - 2));
    return results[n];
}

/*
Recursive vs. iterative
iterative is most likely always faster than recursive since functions have
an overhead of popping and pushing stuff of the call stack
nevertheless iterative does not always win vs recursive implementations since
sometimes recursion can be a lot easier to implement and helps to maintain the code

"Best practice":
Generally favor iteration over recursion, except when recursion really makes sense.
*/
void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1);

    std::cout << "pop " << count << '\n';
}

// Quiz time:
//1
int factorial(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    
    return factorial(n - 1) * n;
}
//2
int sumOfDigits(int number) {
    if (number < 10)
        return number;
    return sumOfDigits(number / 10) + number % 10;

}
//3
unsigned int getInteger() {
    int number {};
    std::cout << "Please enter an integer: ";
    std::cin >> number;
    return static_cast<unsigned int>(number);
}

void printBinary(unsigned int number) {
    if (number > 1)
        printBinary(number / 2);
    std::cout << number % 2 << ' ';
}

int main()
{
    countDown(5);

    for (int count { 0 }; count < 13; ++count)
        std::cout << mem_fib(count) << ' ';
    std::cout << '\n';
     for (int count { 0 }; count < 7; ++count)
        std::cout << factorial(count) << ' ';
    std::cout << '\n';
    std::cout << sumOfDigits(93427) << '\n';
    printBinary(getInteger());

    return 0;
}