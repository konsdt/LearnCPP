#include<iostream>
#include<string>
#include<string_view>

/*
14.13 Class initialization and copy elision

In C++ the compiler is allowed to do all kinds of optimizations to the program
in order to make it more efficient. It only has to always follow the "as-if" rule.
That means it can never change anything in such a way that the programmer can not
know what is happening by reading the source code.
With one noteable exception "Copy elision"
This exception allows the compiler to remove unnecessary copying of objects.

Since this is the one exception from the "as-if" rule it also the reason for
why copy constructors are not allowed to have side effects since they might be
optimized away by the compiler and thus the program will not run as expected.

Also for pass by value and return by value the copy constructor would usually be
called. But they can also be "elided" away and thus it is important, that this
is an optimization that the compiler will perform occasionally.

14.14 Converting constructors and explicit keyword

Implicit conversion only works between non program defined types.
For conversions to or from program defined types, the compiler doese not have
specific rules that tells it how to do it.
Therfore it starts to look for a "user-defined conversion", meaning a function
that was defined by the programmer which helps it to convert between the two
types.

In the below case that would be the constructor of the Foo class.

A constructor that can be used to perform an implicit conversion is called 
a "converting constructor", by default every constructor is a converting 
constructor.

There is a limit on only one user-defined conversion that can be done to perform
an implicit conversion. Therfore we need to tell the compiler that our C-style
string literal that is put into printEmployee() is actually a string view to
avoid it having to be implicitly converted to one.
The other way would be to explicitly construct the Employee object inside
the printEmployee() function.

Due to the implicit conversions it can somtimes be hard to tell whether the 
programmer actually intended the input values to be converted the way they are
or if he completely overlooked that the literal is converted to a class object
in order to print its values.
Thus, there is the "explicit" keyword which tell the compiler that a constructor
is not supposed to be used as a converting constructor

An explicit keyword has two effects:
 * the constructor can not be used to do copy initialization or copy list initialization
 * it can not be used to do implicit conversions since this uses copy list initialization

The modern best practice is to make any constructor that will accept only a single
argument explicit by default. This include constructors with multiple values
where most or all of them have default values.

Do not make copy or move constructors explicit, as these do not perform conversions.
*/

class Dollars {
private:
    int m_dollars {};
public:
    explicit Dollars(int d)
        : m_dollars { d }
    {}
    int getDollars() { return m_dollars; }
};

void print(Dollars d) {
    std::cout << "$" << d.getDollars() << '\n';
}

class Employee {
private:
    std::string m_name {};
public:
    Employee(std::string_view name)
        : m_name { name }
    {}

    const std::string& getName() { return m_name; }
};

void printEmployee(Employee e) { // has an Employee parameter
    std::cout << e.getName() << '\n';
}

class Foo {
private:
    int m_x {};
public:
    Foo(int x)
        : m_x { x }
    {}
    int getX() {
        return m_x;
    }
};

void printFoo(Foo f) {// has a Foo parameter
    std::cout << f.getX() << '\n';
}
int main() {
    using namespace std::literals;
    printFoo(5); // we are supplying an int argument
    printEmployee("Joe"sv);
    print(Dollars{5});

    return 0;
}