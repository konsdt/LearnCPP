#include<iostream>
#include<string>
#include<string_view>
/*
13.8 Overlapping and delegating constructors
To avoid repeating code that overlaps between different constructors we can
"delegate constructors". This means we can call any constructor that we
previously defined inside the member initializer list see example below.
"Best practice:" If there are multiple constructors that use the same code use
delegation to minimize redundancy.

IF the default constructor does some initialization that needs to be done we run
into a problem, since the we can only initialize and delegate in the other con-
structors. Therefore, we should always put code that is important for the setup
in a member function and call it in every constructor.

Resetting a class object:
if we want the class to have a functionality to reset to its default state
(values from the non-static initializer which means values that are hard coded
during definition of the member varibales) we can not get these values in a 
reset member function
Therefore, we need to do something else: We use the accessible assignment operator
*/

class Foo {
private:
    int m_a { 5 };
    int m_b { 6 };
public:
    Foo() {
    }
    Foo(int a, int b)  
         : m_a { a }, m_b { b } {
    }

    void print() {
        std::cout << m_a << ' ' << m_b << '\n';
    }
    void reset() {
        // consider this a bit of magic for now
        *this = Foo{}; // create new Foo object, the use assignment to overwrite
        //our implicit object
    }
    
};




class Employee {
private:
    int m_id {};
    std::string m_name{};
public:
    Employee(int id=0, std::string_view name="")
        : m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    //Use a delegating constructor to minimize redundant code:
    Employee(std::string_view name) : Employee{ 0, name }
    { }
};

int main() {
    Foo a{ 1, 2 };
    a.reset();

    a.print();

    return 0;
}