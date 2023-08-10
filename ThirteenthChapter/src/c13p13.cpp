#include<iostream>


/*
13.13 Static member variables
static member variables are shared by all objects of the class
static member variables can be accessed through the class itself even if
no objects of the class exist.
"Best practice": Access static members by class name (using the scope resolution
operator) rather than through an object of the class (using the member selection
operator).
"Best practice": Prefer initializing static constexpr members at the point of
definition. Prefer making static non-constexpr members inline and initializing them
at the point of definition.

This is e.g used to keep an individual id of every object of a respective class
that was instantiated.
also lookup tables can be made static to have one per class and not one per object.

*/
class Something {
public:
    static int m_value;
};
int Something::m_value{ 1 };

int main() {

    Something first;
    Something second;

    first.m_value = 2;

    std::cout << first.m_value << '\n';
    std::cout << second.m_value << '\n';

    return 0;
}