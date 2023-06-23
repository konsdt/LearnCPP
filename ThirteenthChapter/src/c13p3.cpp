#include<iostream>
#include<array>
#include<cassert>

#define assertm(exp, msg) assert(((void)msg, exp))

/*
13.3 Public vs private access specifiers

Public members are members of a struct or class that can be accessed directly
by anyone, including from code that exits outside the struct or class.

the code outside a struct or class is sometimes considered "the public"
The public can only access the public members of a class which makes sense

by default all members of a struct are public
by default all members of a class are private

private members can only be accessed by other members of the class (or by friends
of the class)

Access specifiers:
private class members can be made public by using the public keyword
* public
* private
* protected

Mixing access specifiers
there is no limit to the number of access specifiers in a class
member variables are usually made private and member functions are usually
made public

"Best practice:"
Make member variables private and member functions public unless there is good reason not to.

access control works on a per-class basis, not a per object basisb.
This means then a function has access to the private members of a class, it can
access the private members of any object of that class type that it can see
*/


class DateClass {
    int m_month {};
    int m_day {};
    int m_year {};
public:
    void setDate(int month, int day, int year) {
        m_month = month;
        m_day = day;
        m_year = year;
    }
    void print() {
        std::cout << m_month << '/' << m_day << '/' << m_year;
    }

    //Note that this function can access the private members of d directly
    void copyFrom(const DateClass& d) {
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

// Quiz
class Point3d {
    int m_x {};
    int m_y {};
    int m_z {};
public:
    void setValues(int x, int y,  int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print() {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z <<">" << '\n';
    }
    bool isEqual(Point3d& p) {
        if ((m_x==p.m_x) && (m_y==p.m_y) && (m_z==p.m_z)) {
            return true;
        }
        else { 
            return false;
        }
    }
};


class Stack {
    std::array<int, 10> m_arr {};
    int m_stack_size {};
public:
    void reset() {
        m_stack_size = 0;
    }
    bool push(int x) {
        if (m_stack_size > 9) {
            return false;
        }
        else {
            m_arr[m_stack_size] = x;
            ++m_stack_size; 
        }
    }
    int pop() {
        assertm((m_stack_size != 0), "Stack is empty.");
        --m_stack_size;
        return m_arr[m_stack_size];
    }
    void print() {
        std::cout << "( ";
        for (int i { 0 }; i < m_stack_size; i++) {
        
            std::cout << m_arr[i]  << ' ';
        }
        std::cout << ')' << '\n';
    }
};
int main() {

    DateClass date;
    date.setDate(10, 14, 2020);
    date.print();
    std::cout << '\n';

    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }


    Stack stack;
	stack.print();
    //stack.pop();
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

    return 0;
}