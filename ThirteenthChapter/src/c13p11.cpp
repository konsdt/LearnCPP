#include<iostream>

/*
13.11 Class code and header files
it is possible to define member functions outside of the class to make
the code more readable, to do so we can use the scope resolution operator
and simply define the member functions as if they were normal functions

access funtions are typically only one line, that is why they are usually
left in the class definition

class definitions can be put in header files, traditionally the class definition
is put in a header file with the same name as the class and the member functions
defined outside the class are put in a .cpp file with the same name as the class
this is common practice and one should get used to do it.. 

13.12 Const class objects and member functions
class objects can be made constant with the const keyword and also must be
initialized during creation
afterwards they can not be changed again (const duh)
but a const class is also only allowed to call const member functions, thus
if the getValue function of the class is not constant, calling it will also
result in a compiler error. 
A const member function will guarantee that it does not modify the object or
call any non-const member functions.
"Best practice": Make any mmeber function that does not modify the state of 
the class object const, so that it can be called by const objects.

The most common way one creates const objects is by passing an object to a
function by const reference. Passing by reference is done to avoid making an
expensive copy of the object we pass and this reference is usually made const
so that we do not allow the function to modify the passed object.
At the same time this also allows the function to work with R-values (e.g literals)
which is fast.

It is possible to overload a member function with just the const keyword
to obtain a non-const and a const version of the same functions. But this
is typically not done and, therefore, uncommon.

As a summary, since passing objects/classes as const ref is common, they should
be written const friendly (member funtions that do not modify the object should
be implemented as const)


*/

class Something {
public:
    int m_value {};

    Something() : m_value{0} { }

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const { return m_value; } // note addition of const keyword after
    // parameter list, but before function body
};

class Date {
private:
    int m_year;
    int m_month;
    int m_day;
public:
    Date(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }
};

//Date constructor:
Date::Date(int year, int month, int day) {
    SetDate(year, month, day);
}

void Date::SetDate(int year, int month, int day) {
    m_month = month;
    m_day = day;
    m_year = year;
}

class Calc {
private:
    int m_value = 0;
public:
    Calc(int value=0);

    Calc& add(int value);
    Calc& sub(int value);
    Calc& mult(int value);

    int getValue() { return m_value; }
};

Calc::Calc(int value) : m_value{value} {
}

Calc& Calc::add(int value) {
    m_value += value;
    return *this;
}
Calc& Calc::sub(int value) {
    m_value -= value;
    return *this;
}
Calc& Calc::mult(int value) {
    m_value *= value;
    return *this;
}



int main() {

    return 0;
}