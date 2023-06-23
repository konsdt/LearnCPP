#include <iostream>

#define PROJECT_NAME "ThirteenthChapter"

/*
13.1 Welcome to object oriented programming

Objects have:
* a list of relevant properties (weight, color, size etc.)
* some number of behaviors that they exhibit (being opened, making sth else hot etc.)

the focus is to the define objects that have a a well-defined set of behaviors
it brings more usefull tools with it like: inheritance, encapsulation, abstraction,
and polymorphism


13.2 Classes and class members

types should not only hold data, but provide functions that work with the 
data as well. 

classes and structs are essentially the same
in addition to holding data, classes (and structs) can also contain functions
that are called "member functions" or "methods"

member functions can use properties of the associated object. This associated
object is so to speak "implicitly passed" to the member function. For this 
reason it is often called "the implicit object"

with member functions we alwoays have an implicit object of the class to work with
one should name member variable with a prepending "m_" this makes is aware that
we change the state of the class when we change such a variabel
also we know to look inside the class for their definition
"Best practice:" Name your classes starting with a capital letter.


inside a class multiple defined functions can call each other and the definition
order does not play a role unlike for normal functions that always need to see
a forward definition first

Member types (or nested types):
in such a case the class name essentially acts like a namespace for the defined 
nested type

"Best practice:" Use the struct keyword for data-only structures. Use the class
keyword for objects that have both data and functions.

Classes are the basis for OOP and this chapter will explore what the have to offer.



*/

// the struct and class are effictively identical
//struct DateStruct {
//    int year {};
//    int month {};
//    int day {};
//};
class DateClass {
    public:
        int m_year {};
        int m_month {};
        int m_day {};
    
    void print() {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

class Employee {
    public:
        std::string m_name {};
        int m_id {};
        double m_wage {};

        // print employee information to the screen
        void print() {
            std::cout << "Name: " << m_name << " Id: " << m_id << " Wage: $" << m_wage << '\n';
        }
};

//Quiz 
//1
class IntPair {
    public:
        int m_number_1 {};
        int m_number_2 {};
    void set(int a, int b) {
        m_number_1 = a;
        m_number_2 = b;
    }
    void print() {
        std::cout << "Pair(" << m_number_1 << ", " << m_number_2 << ")\n";
    }
};


int main() {

    DateClass today { 2023, 6, 23 };
    today.m_day = 24;
    today.print();

    Employee alex { "Alex", 1, 25.00};
    Employee joe { "Joe", 2 , 22.25 };

    alex.print();
    joe.print();
    
    IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
  
}
