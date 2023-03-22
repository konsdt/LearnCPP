#include<iostream>
#include<algorithm>
#include<array>

/*
11.9 Introduction to standard library algorithms
The functionality provided int the algorithms library generally fall into one
of three categories:
* Inspectors: Used to view data in a container (e.g. searching and counting)
* Mutators: Used to modify data in a container (e.g. sorting and shuffling)
* Facilitators: Used to generate a result based on values of the data members.
    (e.g. objects that multiply values or objects that determine what order 
    pairs of elemetn should be soreted in)





- std::find_if find a value that matches a certain condition (like having a certain substring)
- use std::count and std::count_if to count how many occurences there are
- std::for_each takes a list as input and performs the same operation on every element of that list


Using std::sort to custom sort:
std::sort can take a function as its third parameter which returns true if
the first element should be ordered before the second, therefore allowing 
to sort for any condition

"Best practice": Before using an algorithm make sure performance and execution
order guarantees work for your particular use case.

having to pass arr.begin() and arr.end() to every algorithm is a bit annoying but 
c++20 adds ranges which allow us to simply pass arr, this will make the code 
even shorter and more readable
"Best practice": favor using functions from the algorithm library over writing
your own functionality to do the same thing!

*/

int main() 
{
    // std::find:
    // searches for the first occurence of a value in a container
    // takes 3 parameters: iterator to starting element, iterator to ending element
    // value to search for, it returns an iterator pointing to the element if its
    // found or an iterator to the end of the container if it is not found

    std::array arr { 13, 90, 99, 5, 40, 80 };

    std::cout << "Enter a value to search for and replace with: ";
    int search {};
    int replace{};
    std::cin >> search >> replace;

    // input validation omitted

    auto found { std::find(arr.begin(), arr.end(), search) };

    if (found == arr.end())
    {
        std::cout << "Could not find " << search << '\n';
    }
    else
    {
        *found = replace;
    }

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}