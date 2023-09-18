#include<iostream>

/*
14.12 Introduction to the copy constructor

The copy constructor can be used to initialize an object with an object of the
same type passedas the initializer.
It is created implicitly of not provided by the programmer.

The implicit constructor does memberwise initialization, that means every member
of the class is initialized with the value of its corresponding m_variable in 
the copied class.

"Best practice:" Member variables should have no side effects beyond copying.
"Best practice:" Because of the BP above just use the implicit copy constructor.
"Best practice:" If you still need a custom one, use a const lvalue reference as 
parameter in order to avoid accidentaly changing the copied classes values.

One can explicitly request the default copy constructor to be created, but it is 
created implicitly anyways(thus unnecessary). With the same syntax we can also
prevent classes from being copyable.

The copy constructor needs to receive a reference as a value since passing a class
by value implicitly invokes the copy constructor. Thus if we passed the class to
be copied by value the constructor would have to call itself, this would then also be
by value, leading to an infinite chain of calls to the copy constructor....
*/

class Fraction {
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    //Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
        {}

    void print() {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main() {
    Fraction f { 5, 3 };  //Calls Fraction(int, int) constructor
    Fraction fCopy { f }; //What constructo is used here?

    f.print();
    fCopy.print(); 
    return 0;
}