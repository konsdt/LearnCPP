#include<iostream>


/*
12.4 Recursion
A recursive function is a function that calls itself
recursive functions must include a "recursive termination condition"

This output is due to the way the stack works, the termination criterion
like this does not terminate the function but instead it is resumed when it
is cleared of the stack
*/



void countDown(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        countDown(count-1);

    std::cout << "pop " << count << '\n';
}

int main()
{
    countDown(5);
    return 0;
}