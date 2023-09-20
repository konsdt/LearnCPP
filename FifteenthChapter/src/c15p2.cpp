#include<iostream>


/*
15.2 Const class objects and const member functions

You generally want to make your class objects const when you want to ensure
they are not modified after creation.
Data members of const classes can not be modified.
Const objects can not call non-const member functions.
Thus, we need to make the member function const itself.
A const member function guarantees it will not modify the object or call any non-const
member functions as they may modify the object.
const member functions may be called on non-const objects.
"Best practice:" A member function that does not (and will not ever) modify the
state of the object should be mad const, so that it can be called on const objects.

The most common way to receive const objects is when they are passed to a function
by const reference

The this ptr is a const ptr pointing to a const object for const obejcts.
It is possible to overload member functions to have a non const and a const version
of the same member function
This is not done very often

*/

class Date {
private:
    int m_year {};
    int m_month {};
    int m_day {};

public: 
    Date(int year, int month, int day)
        : m_year { year }
        , m_month { month }
        , m_day { day }
    {}

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

// note: We're passing date by const reference here to avoid making a copy of date
void printDate(const Date &date) {
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay()
    << '\n';
}

int main() {
    Date date{2016, 10, 16};
    printDate(date);
    return 0;
}