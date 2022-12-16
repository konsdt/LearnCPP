#include <iostream>
#include <string>
#include <string_view>
// 10.3 Unscoped enumeration input and output
// enumerators are integral symbolic constants, which means enumerated types
// actually hold an integral value
// when an enumerator is defined each of its values is automatically assigned
// an integer value, like so
//
namespace color
{
    enum Color
    {
        black, //assigned 0
        red, // assigned 1
        blue, // assigned 2
        green, //etc. 
        white,
        cyan,
        yellow,
        magenta,
    };
}

// it is possible to explicitly assign the integral values of enumerators
// every following integral value will increase by 1 counting from the explicitly
// assigned value
// "Best Practice": Avoid assigning explicit values to your enumerators unless you
// have a compelling reason to do so.

// Printing enumerator Names:
// this can be done by testing the integral values by using conditional statements
// however this is not very effective, thus it is better to use a switch statement.
// however this version is still quite costly since everytime the function is
// executed a string is created and copyed which is not very efficient.
// From c++17 onwards one can use stringview instead

/**
constexpr std::string_view getColor(color::Color color)
//std::string getColor(color::Color color)
{ 
    switch (color)
    {
        case color::black:     return "black";
        case color::red:       return "red";
        case color::blue:      return "blue";
        case color::green:     return "green";
        case color::white:     return "white";
        case color::cyan:      return "cyan";
        case color::yellow:    return "yellow";
        case color::magenta:   return "magenta";
        default:        return "???";
    out <</

**/
// Using operator overloading we can actually teach operator<< how to print the 
// value of a program-defined enumeration! For now this will be considered magic

std::ostream& operator<<(std::ostream& out, color::Color color)
{
    switch (color)
    {
        case color::black: out << "black"; break;
        case color::red:  out <<  "red"; break;
        case color::blue: out <<   "blue"; break;
        case color::green: out <<   "green"; break;
        case color::white:    out << "white"; break;
        case color::cyan:  out <<   "cyan"; break;
        case color::yellow:  out <<  "yellow"; break;
        case color::magenta:   out << "magenta"; break;
        default:        out << "???";
    }
    return out;
}

// the type of an enumeration can be explicitly given and e.g. made smaller if 
// one is working on a bandwith sensitive project, it is however best practice to#
// Specify the bas type of an enumeration only when absolutely necessary.
// Integer to unscoped enumerator conversion:
// either a base type is given or one uses the static cast to pet option
//
namespace pet
{
    enum Pet
    {
        cat,
        dog,
        pig,
        whale,
    };
}

// we can teach the input operator how to input to type pet::Pet

std::istream& operator>> (std::istream& in, pet::Pet &pet)
{
    int input {};
    in >> input; // input an integer
                 //
    pet = static_cast<pet::Pet>(input);
    return in;

}


int main()
{
    color::Color shirt { color::blue }; // This actually stores the integral value 2
    // unscoped enumerations will implicitly convert to integral values:
    std::cout << "Your shirt is " << shirt << '\n'; // prints "Your shirt is 2"
    // not after teaching the operator
    //std::cout << "Your shirt is " << getColor(shirt) << '\n';
    
    std::cout << "Your shirt is " << shirt << '\n';
 
    pet::Pet pet {};
    std::cin >> pet; // input our pet using std::cin
    
    std::cout << pet << '\n';
    return 0;
}


