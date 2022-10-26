#include <iostream>
#include <string>

// 8.13 Function Templates
// We need a simple version of a function that can work with any parameter type
// even types that were not considered when the code was originally written
// -> Function templates
// the compiler can use a single template to generate a family of related functions
// or classes, each using a different set of types
// templates can work with types that did not even exist when the template was 
// written. This helps make the template code both flexible and future proof!
// When a function template is created, it is created using "template types"
// these are placeholder types for any future types that might be used later on

// "BEST PRACTICE": Name the template types with a single capital letter
// starting with T (e.g.: T,U,V,...etc.)
namespace math
{
    template <typename T> //this is the template parameter declaratio
    T max(T x, T y) 
    {
    return (x > y) ? x : y;
    }
}
// each template function (or template class) needs its own template parameter
// declaration
// 
// 8.14 Function template instantiation
// to use the function template max<T> the syntax is the following
// max<actual_type>(arg1, arg2);
// "Template argument deduction":
// when the type of the arguments matches the actual type we want we can just skip
// giving the template a type. The funtion will automatically instantiate to the
// parameter type
// "BEST PRACTICE": Favor the normal function call syntax when using function templates.
// 
// "Function templates with non-template parameters":
// One can create function templates that have both template Parameters and non-template parameters
// 
// "Using function templates in multiple files"
// the compiler needs to see the full definition of the template in order
// to be able to instantiate it. Therefore templates are typically written in 
// header files, where they can be #included into any code file that wants to use them
// Template definitions ar not subject to the one-definition rule, and functions 
// instantiated from function templates are implicitly inline, so they are exempt
// from the one-definition rule 

namespace examples
{
    template <typename T>
    T someFcn(T x, double y)
    {
        return 5;
    }
    template <typename U>
    U addOne(U x)
    {
        return x + 1;
    }
}

// "Generic Programming":
// template types are somtimes called "generic types"
// thus programming with templates is sometimes called "generic programming"
// This allows to not worry so much about type information but rather lets one
// focus on the logic of algorithms
// 
// Disadvantages of Templates:
// A seperate function is created for every unique function call, this can 
// quickly lead to code bloat and thus very long compile times.
// The bigger downside is however, that they can quickly produce crazy looking
// extremely long and intimidating error messages that take some getting used to.
//
// "BEST PRACTICE": Use function templates to write generic code that can work
// with a wide variety of types whenever you have the need to.
//
//
int main() {

    std::cout << math::max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int,int)
    std::cout << math::max<int>(4, 3) << '\n'; // instantiates and calls function max<int>(int,int)
    std::cout << math::max<double>(1, 2) << '\n'; // instantiates and calls function max<int>(int,int)
    // type deduction works for both examples below:
    // The lower way will also consider other function overloads with the same name
    // whereas the upper will only use the template
    std::cout << math::max<>(2.5, 2.6) << '\n';
    std::cout << math::max(2, 3) << '\n';
    // this compiles and runs   
    std::cout << examples::addOne(1) << '\n';
    std::cout << examples::addOne(2.3) << '\n';
    // this will not compile:
    //std::string hello{ "Hello world!" };
    //std::cout << examples::addOne(hello) << '\n';
    // this is because std:string + 1 does not make sense!
    return 0;
}
