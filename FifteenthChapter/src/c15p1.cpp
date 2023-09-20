#include <iostream>

/*
15.1 The hidden this pointer and member function chaining
every member function can use the "this" keyword as an implicit constant ptr
that holds th address of the current implicit object

Explicitly referencing this is unneccesry most of the time, but there are a 
few occasions where it becomes necessary
1. When a member function has a parameter that matches the name of a member variable
then they can be separated by using the this ptr.
(it is like self in python)
2. Sometimes it can be usefull that a member function returns the implicit *this
ptr This allows member functions to be chained together.
It is also the most commin explicit use of "this" and one should consider
using it whenever it makes sense to chain member functions together.

If we need a functionality to reset a class to a default state, *this can also
be used to write a reset member function.

*/

class Simple {
private:
     int m_id {};
public:
     Simple(int id)
          : m_id { id }
     {}

     int getID() { return m_id; }
     void setID(int id) { m_id = id; }

     void print() { std::cout << this->m_id; } //use this ptr to access the implicit
     //object and operator-> to select member m_id
};


int main() {
     Simple simple{1};
     simple.setID(2);

     simple.print();
 
     return 0;
}
