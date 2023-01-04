#include <iostream>


// 10.10 Class templates
// For functions the solution for having to create overloaded functions for
// every type we want to work with is creating template functions for which
// the compiler can deduce the type from the passed arguments
//
// for aggregated types one faces similar challenges but the problem with aggregated
// types is that unlike functions they can not be overloaded
// The solution are Class templates.
//
// "Class templates"
// the principle works exactly the same as for function templates,
// the definition starts with a "template" keyword followed by angled brackets in which
// all template types we need are specified by using the prefered keyword "typename"
//
// But how can we now use the templated struct in a function without having to explicitly
// overload the respective function every time??
// No of course we can also use a templated function to do that like below
// we simply pass the templated type as type for the templated struct type that
// is passed to the function

template <typename T>
struct Pair 
{
    T first {};
    T second {};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first > p.second ? p.first : p.second);
}

// Class templates can have some members using a template type and other members 
// using a normal type like example below:

template <typename T>
struct Foo
{
    T first {};
    int second {};
};


// a class can also have multiple template types
template <typename T, typename U>
struct Bar
{
    T first {};
    U second {};
};

// since working with pairs of data is common in c++ there ist a std::pair in 
// the utility header which should be used in practice.

// 10.11 Class template argument deduction (CTAD)
// starting with c++17 the compiler can deduce the template types form the types
// of the objects intitializer
// This only works if no argument list is provided
// c++17 does not know how to automatically deduce types of aggregate types
// therefore the programmer can tell it using a deduction guidline like below:

//template <typename T, typename U>
////Pair(T, U) -> Pair<T, U>;


int main()
{
    Pair<int> p1 { 5, 6 };
    std::cout << p1.first << ' ' << p1.second << "\n";
    std::cout << max(p1) << " is larger\n";

    Pair<double> p2 { 1.2, 3.4 };
    std::cout << p2.first << ' ' << p2.second << "\n";
    std::cout << max(p2) << " is larger\n";
 
    Pair<double> p3 { 7.8, 9.0 };
    std::cout << p3.first << ' ' << p3.second << "\n";
    std::cout << max<double>(p3) << " is larger\n";

    // CTAD and function template auto type deduction
    Pair p4 { 1, 0 }; 
    std::cout << p4.first << ' ' << p3.second << "\n";
    std::cout << max(p4) << " is larger\n";

    return 0;
}
