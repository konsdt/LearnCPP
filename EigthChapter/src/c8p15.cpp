#include <iostream>


// 8.15 Function templates with multiple template types
//

// std::cout << max(1, 2) << '\n'; // will instantiate max(int, int)
// std::cout << max(1.5, 2.5) << '\n'; // will instantiate max(double, double)
// what will not compile is a function call to max with mixed data types
// std::cout << max(2, 3.5) << '\n';
// this is because type conversion is only done when resolving function
// overloads and not when performing template argument type deduction
// this can still be done with a template if we simply specify the type
// explicitly by using the angled brackets:
// std::cout << max<double>(2, 3.5) << '\n';
// this is fine but it would be better if we did not even have to think about
// the types when making a function call to max
// we can reach that goal by defining multiple template type parameters like
// implemented below:
// in this case we actually need an auto return type for the template,
// otherwise we could easily run into the problem that the given return type
// does not match the actual return type and this would then lead to some
// really hidden and nasty bug behavior
// 
// "abbreviated function templates":
// with c++20 a new use of the auto keyword was introduced
// it now allows to write abbreviated versions of function templates:
// auto max(auto x, auto y)
// {
//      return (x > y) ? x : y;
// }
// which is short for the below:
template <typename T, typename U>
auto max(T x, U y)
{
    return (x > y) ? x : y;
}

// "BEST PRACTICE": Feel free to use abbreviated funtion templates with a single
// auto parameter, or where each auto parameter should be an independent type 
// (and your language standard is set to C++20 or newer)


int main()
{
    std::cout << max(2, 3.5) << '\n';

    return 0;
}
