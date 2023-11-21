#include <iostream>
#include <vector>
/*
16.1 Introduction to containers and arrays
containers are used when we need to work with a set of related values
strings are also containers of several chars
elements of containers do not have names, such that they can have as many
elements as we want without giving each one a unique name
containers are homogeneous (only one type of element)

an array is a container that stores a sequence of values contiguously (each element
is placed in an adjacent memory location)
three types of arrays: (C-style) arrays, std::vector, std::array
std::vector is the most flexible
C-style is inherited for backwards comaptibility
and std::array was introduced as replacement for the above in c++11

16.2 Introduction to std::vector and list constructors
"Best practice:" Use list initialization with an initializer list of values
to construct a container with those element values.

the subscript operator can be used [] to access array elements
C++ is zero-based: it starts counting at 0
the subscript operator does not do any bounds checking... this is dangerous!

When constructing a class type object a matching list constructor is selected 
over other matching constructors.

"Best practice:" When constructing a container (or any type that has a list 
constructor) with initializers that are not element values, use direct initialization.
    // vector containing 10 int elements, value-initialized to 0:
    std::vector<int> data(10);
When a std::vector is a member of a class type it is not obvious how to provide 
a default initializer that sets the length od a std::vector to some initial value:
struct Foo
{
    std::vector<int> v{ std::vector<int>(8) }; // ok
};

const vectory must be initialized and can not be modified
it is not possible to make std::vector a constexpr, if that is needed we have
to use the std::array class

The name vector is actually chosen wrongly and should have been called array
but it is too late to change that now.
*/

int main() 
{
    // value initialization (uses default constructor)
    std::vector<int> empty{}; //vector containing 0 int elements    
    std::vector<int> primes { 2, 3, 5, 7, 11 };
    std::vector<char> vowels { 'a', 'e', 'i', 'o', 'u'};

    std::cout << "The first prime number is: " << primes[0] << '\n';
    std::cout << "The second prime number is: " << primes[1] << '\n';
    std::cout << "The sum of the first 5 primes is: " << primes[0] + primes[1] +
        primes[2] + primes[3] + primes[4] << '\n';
    //arrays are contiguous in memory:
    std::cout << "An int is " << sizeof(int) << " bytes.\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';

    // class template argument deduction (CTAD):
    std::vector squares { 1, 4, 9, 16, 25 };

    // explicit template type argument for temperature
    std::vector<double> daily_high_temperature (365);

    // program
    std::vector<int> integral_vals (3);
    std::cout << "Please enter 3 integer values: "; 
    std::cin >> integral_vals[0];
    std::cin >> integral_vals[1];
    std::cin >> integral_vals[2];

    std::cout << "The sum is: " << integral_vals[0] + integral_vals[1] + integral_vals[2] << '\n';
    std::cout << "The product is: " << integral_vals[0] * integral_vals[1] * integral_vals[2] << '\n';
    return 0;
}
