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
*/


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

int main() {
    Accumulator acc{};
    acc.add(5);

    print(acc);

    return 0;
}
