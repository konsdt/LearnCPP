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
*/
int main() {

    return 0;
}