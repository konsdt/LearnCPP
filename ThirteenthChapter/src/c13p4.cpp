#include<iostream>
#include<cassert>

/*
13.4 Access functions and encapsulation
Encapsulation:
    process of keeping the details about how an object is implemented hidden
this is done with access specifieres, ussually all member variable of a class
are private and mosly all member functions are public
Benefit: easier usage and reduction of complexity of the program
Benefit: help protect the data and prevent misuse
Benefit: encapsulated classes are easier to change
Benefit: They are easier to debug
"Access functions"
short public function to retrieve or change the value of a private member variable
-> Getters and Setters
Gettters: only read access: return by value or const reference

* if a member does not need access from outside: do not provide access functions
* if they need access, first think if a behavior or action can instead be exposed
* if that is not possible consider if only a getter can be provided

13.5 Constructors
How do we initialize a class with private member variables? -> Constructors
For public member variables one can use aggregate initialization (list-initialiazation)
Rules:
    * must have same name as class (with same capitilization)
    * no return type
    * after it executes the object should be in a well-defined, usable state

A default constructor is one that take no parameters, it is called if no user-
provided initialization values are given
"Best practice:" Favor value-initialization over default-initialization for class objects.

Constructors can also decalred with parameters
"Best practice:" Favor brace initialization to initialize class objects.

"Best practice:" If you have constructors in your class and need a default constructor
that does nothing (e.g. because all your members are initialized using non-static
member initialization), use "= default".

Classes containing class members
During declaration of the class object all contained class objects are 
default initialized, this even happens before the body of the constructor executes


Constructor have two purposes:
    1. They determine who is allowed to create an object of the class type.
    That is an object of a class can only be created if a matching constructor
    can be found.
    2. The are used to initialize objects.
"Best practice:" Always initialize all member variables in your objects
*/

//Quiz time

class Ball {
private:
    std::string m_color {"black"};
    double m_radius {10.0};
public:
    Ball() {}
    Ball(std::string color) {m_color = color;}
    Ball(double radius) {m_radius = radius;}
    Ball(std::string color, double radius) {m_radius = radius; m_color = color;}

    void print() {
        std::cout << "color: " << m_color << ", " << "radius: " << m_radius << '\n';
    }
};

class A {
public:
    A() { std::cout << "A\n"; }
};

class B {
private:
    A m_a; // B contains A as member variable
public:
    B() { std::cout << "B\n"; }
};

class Fraction {
private:
    int m_numerator {};
    int m_denominator {};
public:
    Fraction(int numerator=0, int denominator=1) {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main() {
    Fraction frac{}; // value initialization using empty set of braces
    Fraction frac1; // Default-initialization, calls default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '\n';
    Fraction  fiveThirds {5, 3}; // List initialization calls Fraction(int, int)
    Fraction threeQuarters(3, 4); // Direct initialization, also calls Fraction(int, int)
    
    B b;


    Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

    return 0;
}