#include <iostream>

// 4.12 Type conversion and static_cast
// 
// implicit type conversions:
// Some type conversions are always safe to make: e.g.: int to double, while
// others might result in the value being changed during conversion: double to int.
// Unsafe implicit conversions result in a warning or in case of brace initialization
// ({}) in an error. This is one of the main reasons why brace initialization is 
// preferred
// will be treated in more depth later, "meaty topic"
//
// explicit type conversions:
// in most cases this will be done by the static_cast operator
// syntax: static_cast<new_type>(expression)
// whenever one sees c++ syntax with <> the thing between the brackets is most
// likely a type. This is how c++ deals with concepts that need a parameterizable
// type. Exluding: PreProcessor synta whenever one sees c++ syntax with <> the thing between the brackets is most
// likely a type. This is how c++ deals with concepts that need a parameterizable
// type. Exluding: PreProcessor syntaxx
// static_cast will produced undefined behavior if the value being voncerted
// does not fit in range of the new type!

void print(int num) 
{
    std::cout << num << '\n';
}

int main()
{   
    char ch { 97 };
    //explicitly convert double value to an int
    print( static_cast<int>(5.5) );
    //using static_cast to convert char to int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';
    // static_cast evaluates as an expression, the variable ch that is passed
    // into it is not effected by the casting in the expression above.
    return 0;
}
