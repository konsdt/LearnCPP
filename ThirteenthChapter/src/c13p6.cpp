#include<iostream>

/*
13.6 Constructor member initializer lists
"Best practice:" Use member initializer lists to initialize your class member 
variables instead of assignment.
RULE: const member must initialized and can only be initialized using the intitializer
lists (which you should do anyway)


before c++11 one could only zero initialize a member array
however afterwards it is possible to fully intitialize a member array using uniform
intitilization

they can also be used to initialize member variables which are classes themselves
*/

//Quiztime


class RGBA {
private:
    std::uint8_t m_red {};
    std::uint8_t m_green {};
    std::uint8_t m_blue {};
    std::uint8_t m_alpha {};
public:
    RGBA(std::uint8_t red=0, std::uint8_t green=0, std::uint8_t blue=0, std::uint8_t alpha=255)
    :  m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha } 
    {
    }
    void print() {
        std::cout << "r=" << static_cast<int>(m_red) 
        << " g=" << static_cast<int>(m_green) 
        << " b=" << static_cast<int>(m_blue) 
        << " a=" << static_cast<int>(m_alpha) 
        << '\n';
    }
};
class A {
public:
    A(int x = 0) { std::cout << "A " << x << '\n';  }
};

class B {
private:
    A m_a {};
public:
    B(int y) : m_a{ y - 1 }
    {
        std::cout << "B " << y << '\n';
    }
};

class Something {
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};
    const int m_value4 {};
    const int m_array[5];
public:
    Something(int value1, double value2, int value4, char value3='c')
        : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 } , m_value4{ value4 }, m_array {1, 2, 3, 4, 5 } //directly initialize the member variables
        {
            //no need for assignement here
        }
    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value4 << ", " << m_value3 << ")\n";
    }
};

int main() { 
    Something something{ 1, 2.2, 2 };
    something.print();
    
    B b { 5 };

    RGBA teal{ 0, 127, 127 };
	teal.print();
    return 0;
}