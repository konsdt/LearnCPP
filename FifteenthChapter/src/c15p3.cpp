#include<iostream>

/*
15.3 Classes and Header files
"Best practice:" Member functions with a trivial, one line implementation can be
defined inside he class definition. 
Member functions with a complex or multi-line implementation should be defined
outside the class definition, in a source file.

Classes can be defined inside header files, but they need to contain the full
definition of a class rahter than just a forward declaration of the class 
(like sufficient for functions)
"Best practice:" Class Definitions should be put in header file with the same
name as the class. Trivial member functions can be defined inside the class.
One should prefer to define non-trivial member functions in a source file with 
the same name as the class.

Functions defined inside the class definition are implicitly inline, which allows
them to be #included into multiple code files without violating the ODR (one 
definition rule) Functions defined outside the class defintion are not implicitly
inline. They can be made inline by using the "inline" keyword.
"Best practice:" Put any default arguments for member functions inside the class
definition.

15.4  Nested types
"Best practice:" Define any nested types at the top of your class type.


15.5 Introduction to destructors

Destructor: Function that is called automatically when an object of a non-aggregate
class type is destroyed. 

1. Destructor must have the same name as the class. preceded by tilde (~)
2. It can not take arguments
3. It does not have a return type

We can have a destructor call functions of the class that always need to be
executed before the class is destroyed. One example would be a sendData()
function that always needs to be executed to make sure all of the data has been
send before the class object is destroyed.

If there isn't a user defined destructor function the compiler will generate
an implicit one which is fine if there is no cleanup to be done

std::exit is problematic, since it will prevent all destructors from being 
executed!!

The same holds for unhandeled exceptions which might also lead to termination and
no stack unwinding which might leave destructors unexecuted.
*/

class Simple {
private:
    int m_id {};

public:
    Simple(int id) 
        : m_id { id } {

        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() {
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() { return m_id; }
}; 

int main() {
    // Allocate Simple
    Simple simple1 { 1 };
    {
        Simple simple2 { 2 };
    } // simple2 dies here


    return 0;
} // simple1 dies here