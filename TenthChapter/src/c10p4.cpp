#include <iostream>
#include <string_view>

// 10.4 Scoped enumerations (enum classes)
// although unscoped enums are distinct types they are not type safe. This means
// that since they evaluate as integers different enum types can be compared
// against another which can lead to weird scenarios not erroring out.
// e.g. testing whether a type of fruit or a color are the same.. syntax correct
// semantically bullshit
//
// To work aroung this there are Scoped enumerations!
// They are strongly typed(do not implicitly convert to integers) and strongly scoped
// (enumerators are only placed in the scope region of the enumeration)
// even though scoped enums use the "class" keyword they are not considered 
// to be class types. This is reserved for structs, classes and unions... yay :D
// 
// Scoped enumerations define their own scope regions, thus they are a way of
// namespacing an enumeration, therefore we do not need to explicitly put
// them in any namespace
// Generally "Best practice": Favor scoped enumerations over unscoped enumerations
// unless there's a compelling reason to do otherwise.

// Easing the conversion of scoped enumerators to integers
// the lack of implicit conversion to integer can often be a pain point, especially
// if we want to use the enums as indices for arrays or something similiar.
// In such cases, having to use static_cast every time will clutter your code
// Thus a common workaround is to overload the uniary operator to perform this 
// conversion
//
/**
enum class Animals
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,

    maxAnimals,
};

//Overload the unary + operator to convert Animals to the unerlying type
constexpr auto operator+(Animals a) noexcept
{
    return static_cast<std::underlying_type_t<Animals>>(a);
}


**/
enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};


constexpr std::string_view getAnimalName(Animal animal)
{
    using enum Animal;
    switch (animal)
    {
        case pig:  
          return "pig";
        case chicken: 
          return "chicken";
        case goat: 
          return "goat";
        case cat:
          return "cat";
        case dog: 
          return "dog";
        case duck: 
          return "duck";
        default: 
          return "Error animal not named\n";
    }
}



void printNumberofLegs(Animal animal)
{
    using enum Animal;
   
    const std::string_view name { getAnimalName(animal) };
    std::cout << "A " << name << " has ";
    
    switch (animal)
    {
        case pig:
        case goat: 
        case cat: 
        case dog: 
          std::cout << 4;
          break;
        case duck:
        case chicken:
          std::cout << 2;
          break;
        default:  
          std::cout << "???"; 
          break;
    }

    std::cout << " legs.\n";
}


int main()
{
   /** 
    enum class Color // "enum class" deines this as a scoped enumeration rather than an unscoped enumeration
    {
        red,
        blue,
    };

    enum class Fruit
    {
        banana,
        apple,
    };


    Color color { Color::red }; //red is not directly accessible, one has to use Color::red
    Fruit fruit { Fruit::banana }; //banana is also not directly accessible
**/
/**
    if (color == fruit) // compile error: the compiler does not know how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

**/

   // std::cout << +Animals::elephant << '\n'; //convert Animals::elephant to an integer using unary operator+

    printNumberofLegs(Animal::cat);
    printNumberofLegs(Animal::chicken);

    return 0;
}
