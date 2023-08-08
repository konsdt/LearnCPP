#include<iostream>

/*
13.10 The hidden "this" pointer 
simple.setID(2); is translated to
setID(&simple, 2); during compilation
this changes simple from a prefix to a function argument!
It is passed by address!
But since the member function now receives an additional 
argument its definition also has to be changed to the following
void setID(Simple* const this, int id) { this->m_id = id; }
-> allows to access attributes of objects passed by pointer to a function.
it will resolve to simple.m_id
The "this pointer" is a hidden const pointer that holds the address of the object
the member function was called on
Any member variables are prefixed with "this->" which in python would "translate"
to "self."

"this" always points to the object being oberated on

explicitly referencing this can be done for example if there is a member variable
with the same name as a parameter of the constructor we can then do:
this->data = data;
self.data = data

chaining member functions together (like I know from pandas) we need the
member functions to return the object they were working on, this can be done
by returning the *this pointer at the end of the member function so any member 
function can keep working on the object directly


*/

class Calc {
private:
    int m_value { 0 };
public:
    Calc& add(int value) {m_value += value; return *this; }
    Calc& sub(int value) {m_value -= value; return *this; }
    Calc& mult(int value) {m_value *= value; return *this; }

    int getValue() { return m_value; }
};

class Simple {
private:
    int m_id;
public:
    Simple(int id)
        : m_id{ id } {
        }
    
    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};

int main() {

    Simple simple{1};
    simple.setID(2);
    std::cout << simple.getID() << '\n';

    Simple A{1}; // this = &A inside the Simple constructor
    Simple B{2}; // this = &B inside the Simple constructor
    A.setID(3); // this = &A inside member function setID
    B.setID(4); // this = &B inside member function setID

    Calc calc{};

    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n';
    return 0;
}