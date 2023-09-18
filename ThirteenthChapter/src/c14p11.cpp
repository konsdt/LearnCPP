#include<iostream>

/*
There has been restructuring as of September 11th 2023. This changed the order
and content of a lot of chapters but I will try to continue with chapter 14.11
since I hope to have covered most of what came before.

14.11 Temporary class objects
Case 1: IntPair is instantiated but it is really only used once 
so there is no need for a variable -> instead use a temporary object 
temporary objects are also called anonymous object or unnamed object
it has no name and only exists for the duration of of a single expression

This can be done in two ways: Case 2: Explicitly and Case 3: Explicitly

a temporary class object is an rvalue, Thus, such objects can only be used where
rvalue expressions are accepted.


*/

class IntPair {
private:
    int m_x {};
    int m_y {};
public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() { return m_x; }
    int y() { return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}


int main() {

    //Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p); // print(3, 4)

    //Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 });

    //Case 3: Implicitly convert { 7, 8 } to a temporary IntPair and pass to 
    //function
    print( { 7, 8 } );
    return 0;
}