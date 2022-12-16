#include <iostream>

#define PROJECT_NAME "CompoundTypesEnumsAndStructs"

// 10.1 Introduction to program-defined (user-defined) types
// c++ has to categories of compound types that allow for this:
//  1. enumerated typed(scoped and unscoped enumerations)
//  2. class types (includeing structs, classes and unions)
// "Best practice:" Name your program-defined types starting with a capital letter
// and do not use a suffix.
// "Best practice": A program-defined tsype used in only one code file should be 
// defined in that code file as close to the first point of use as possible.
//
// A program-defined type used in multiple code files should be defined in a header
// file with the same name as the program-defined type and the #included into
// each code file as needed.
// 
// Type definitions are paritally exempt from the one-definition rule. But we can
// only have one definition in a single code file and every definition in other
// code files must match.
// 
// 10.2 Unscoped enumerations
// An enumeration is a compound type where every possible value is defined as a 
// symbolic constant (called an enumerator).
// Unscoped enumerations:
//
// Unscoped enumeration
enum Color
{
    //Here are the enumerators
    //These symbilc constants define all the possible values this type can hold
    //Each enumerator is seperated by a comma, not a semicolon
    red,
    green,
    blue, //trainling comma optional but recommended
};

// "Best practice": Name your enumerated types starting with a capital letter.
// Name your enumerators starting with a lower case letter
// They are usefull for enhancing code documentation and readability.
// They are best used when one has a smallish set of related constants, and objects
// only need to hold one of the values at a time.
// Commonly defined enumerations include days of the week, the cardinal directiond,
// and the suits in a deck of cards.

/**
enum DayOfWeek
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

enum CardinalDirections
{
    north,
    east,
    south,
    west,
};

enum CardSuits
{
    clubs,
    diamonds,
    hearts,
    spades,
};

// status codes to indicate to the caller of a function whether the function 
// executed correctly

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

FileReadResult readFileContents()
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

**/

// Unscoped enumerations are named such because they put their enumerator names
// into the same scope as the enumeraation definition itself. Therefroe one enumerator
// name can not be used in several enums if they are both defined in the global
// namespace. Therefore:
// "Best practice": Prefer putting your enumerations inside a named scope region
// (such as a namespace or class) so the enumerators do not pullut the global
// namespace.


//Quiz

namespace monsterType 
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        orge,
        skeleton,
    };
}



// Define a program-defined type named Fraction so the compiler understands what
// a Fraction is
// It only defines what a Fraction type looks like and does not create one
struct Fraction
{
    int numerator {};
    int denominator {};
};



int main() {
    
//    Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f
    
//    Color apple { red };    // my apple is red
//    Color shirt { green };  // my shirt is green
//    Color cup { blue };     // my cup is blue

//    Color socks { white }; // error: white is not an enumerator of Color
    
    monsterType::MonsterType monster { monsterType::troll };

    return 0;
}

