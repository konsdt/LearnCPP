#include <iostream>

#define PROJECT_NAME "TypeConversionAndFunctionOverloading"


// 8.1 Implicit Type Conversion
// the process of converting a value of one data type to another data type
// e.g. when initializing a double with an integer
// or when the type of return value is different from the functins delcared 
// return type
// or when using certain binary operators with operands of different types
// or when using a non boolean value in an if statement
// or when an argument passed to a function has a different type than the
// function parameter
//
// 8.2 Floating-point and integral promotion
// "Numeric promotion":
// in any architecture it is not guaranteed that cpus have efficient ways of
// manipulating objects narrower (e.g. 8bits) than the standard width (eg. 32 bits)
// therefore numeric promotion is used to make the objects wider and thus allow
// them to be processed efficiently, it is value preserving and therefore safe
// to freely use whenever required
// It also reduces redundancy!
// Two categories:
// "floating point promotions"
// float value can be converted to double values
void printDouble(double d)
{
    std::cout << d << '\n';
}
// "Integral promotions"
// These allow for the types short,char,bool to be promoted to type int
//
// 8.3 Numeric Conversions
// all other conversions that do not go from a narrower type to a wider type
// these do not have to be value preserving and thus for most of them the 
// compiler will issue a warning, but: conversiones between signed and unsigned 
// ints will often not be warned about so one has to be extra carefull with them
//
// narrowing conversions should be avoided in general, but if not possible they
// should be made explicit using static_cast -> thus the compiler knows that
// the narrowing conversion is intentional and will not issue a warning
//
// 8.4 Arithmetic conversions
// Some operators including the arithmetic ones require the operands to be of the
// same type -> what happens if that is not the case is implicit conversion to one of the two
// operands types. This is done according to a priorization list
// the higher priority type will be chosen
// this can lead to problem again when mixing unsigned and signed types
//
// 8.5 Explicit type conversion (casting) and static_cast
// c++ supporsts 5 different types of casts: "C-style casts", "static casts",
// "const casts", "dynamic casts", "reinterpret casts"
//
// Avoid "const casts" and "reinterpret casts" unless there is a very good reason
// to use them since they can be harmful when used incorrectly
//
// "C-style casts":
// they can perforem const reinterpret or static casts behind the curtains
// thus best practice is to avoid them aswell when possible
//
// "static-cast":
// takes an expression as an input, and returns the evaluated value converted to
// the type specified inside the angled brackets. it is best used to convert one
// fundamental type into another. It is best practice to use it in c++
//
//
//
int main() {
    //implicit type conversion:
    double x{ 3 };
    // impossible conversion:
    // int x{ 4.5 };
    // brace initialization dissallow type conversions that lead to data loss
    
    printDouble(5.0);
    printDouble(4.0f);

    return 0;
}
