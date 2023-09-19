#include<iostream>
#include<cmath>
/*
14.x Quiztime
*/


//Q1

class Point2d {
private:
    double m_x {0.0};
    double m_y {0.0};
public:
    Point2d() = default;
    Point2d(double x, double y)
        : m_x { x }, m_y { y }
    {}

    void print() { std::cout << "(x, y): "<< m_x << ", " << m_y << '\n'; }

    double distanceTo(Point2d p) {
        return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
    }
};


class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };
public:
    Fraction() = default;
    explicit Fraction(int numerator, int denominator)
        : m_numerator {numerator}, m_denominator {denominator}
    {}

     void getFraction(); // defined below
    
    Fraction multiply(const Fraction& f)
    {
        return Fraction{ m_numerator * f.m_numerator, m_denominator * f.m_denominator };
    }

    void printFraction() {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

void Fraction::getFraction()
{
    std::cout << "Enter a value for numerator: ";
    std::cin >> m_numerator; // this is a member function, so we can access members directly
    std::cout << "Enter a value for denominator: ";
    std::cin >> m_denominator;
    std::cout << '\n';
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    
        Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
    
    return 0;
}