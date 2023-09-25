#include<iostream>
#include<ios>
#include<string>

/*
15.6 Class templates with member functions

Calls templates allos us to use template parameters for the type of our data 
members of class types (struct, classes and unions).

"Best practice": Any member function templates defined outside the class definition
should be defined just below the class defintion in the same file.


*/

template <typename T>
class Pair {
private:
    T m_first {};
    T m_second {};
public:
    Pair(const T& first, const T& second)
        : m_first { first }, m_second { second }
    {}

    bool isEqual(const T& first, const T& second);

};

//Question 1

template <typename T, typename Q, typename R>
class Triad {
private:
    T m_first {};
    Q m_second {};
    R m_third {};

public:
    Triad(const T& first, const Q& second, const R& third) 
        : m_first {first}, m_second {second}, m_third {third}
    {}
    T getFirst() { return m_first; }
    Q getSecond() { return m_second; }
    R getThird() { return m_third; }

    void print();
};

template <typename T, typename Q, typename R>
void Triad<T,Q,R>::print() {
    std::cout << m_first << ' ' << m_second << ' ' << m_third << '\n'; 
}


//Here is a deduction guide for our Pair (required in C++17 or older)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
template <typename T>
bool Pair<T>::isEqual(const T& first, const T& second) {
    return (m_first == first && m_second == second);
}
int main() {

	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();

	using namespace std::literals::string_literals;
	Triad t2{ 1, 2.3, "Hello"s };
	t2.print();


    Pair<int> p1 { 5, 6};
    std::cout << std::boolalpha << "isEqual(5, 6): " << p1.isEqual(5, 6) << '\n';
    std::cout << std::boolalpha << "isEqual(5, 7): " << p1.isEqual(5, 7) << '\n';
    return 0;
}