#include<iostream>

/*
15.8 Friend non-member functions
In C++ a friend is a class or function (member or non-member) that has been
granted full access to the private and protected members of another class.

Still the friendly functions must be passed an explicit class object argument
in form of a const reference to work with.

"Best practice:" A friend function should prefer to use the class interface
over direct access whenever possible.
"Best practice:" Prefer to implement a function as a non-friend when possible and
reasonable.

15.9 Friend classes and friend member functions
-> it can access private members of its friend.
the friend of the class can not access the *this pointer of the befriended class
since *this is actually a function parameter

- friendship is not reciprocal: class A is friend of class B does not mean class B
  is friend of A
-friendship is not transitive: class A friend of class B, class B is friend of 
  class C does not mean that class A is friend of class C
- friendship is not inherited, derived classes from a friend class are not 
  automatically friends as well

it is also possible to only make a member function of another class a friend
but this is rather complicated, since the order of declaration and definitions
matters a lot for the compiler in such a case
the member function must be declared outside of its own class  
*/

class Storage; // forward declaration for class storage

class Display {
private:
    bool m_displayIntFirst {};
public:
    Display(bool displayIntFirst)
        : m_displayIntFirst { displayIntFirst }
    {}

    void displayStorage(const Storage& storage); // forward declaration for
    // Storage needed for reference here
};

class Storage {
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
        : m_nValue { nValue }, m_dValue { dValue }
    {}
    // Make the Display::displayStorage member funtion a friend of the Storage
    // class
    // Requires seeing the full definition of class Display (as displayStorage is 
    // a member)
    friend void Display::displayStorage(const Storage& storage);
};

// Now we can define Display::displayStorage 
// Requires seeing the full definition of class Storage (as we access Storage members)
void Display::displayStorage(const Storage& storage) {
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else //display double first
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
}

class Accumulator {
private:
    int m_value { 0 };
public:
    void add(int value) { m_value += value; }

    // friend declaration that makes the following non-member function a friend
    // of Accumulator
    friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator) {
    std::cout << accumulator.m_value;
}



//





int main() {
    Accumulator acc{};
    acc.add(5);

    print(acc);
    std::cout << '\n';
    Storage storage { 5, 6.7 };
    Display display { false };
    display.displayStorage(storage);

    return 0;
}
