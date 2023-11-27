#include <iostream>
#include <vector>
/*
16.8 Array indexing and length using enumerators
unscoped enumerations implicitly convert to std::size_t such that they can 
be used to index arrays in a meaningful way

"Best practice:" Use a static_assert to ensure the length of your constexpr
array matches your count enumerator. Use an assert to ensure the length of your
non-constexpr array matches your count enumerator.

Since unscope enums clutter up the namespaces it is sometimes better to use
a scoped enumeration. The problem here is that they do not implicitly 
convert to size_t, thus we might run into sign conversion issues.
We can solve this by most obviouly just using a static_cast<size_t> but this 
clutters up the code quite a bit.
There is another solution to overload the operator+ like in the following.
But if one is doing a lot of enumerator to integral conversions, it is probably
better to just use a standard enum inside a namespace (or class)
*/

enum class StudentNames 
{
    kenny,
    kyle,
    stan,
    butters,
    cartman,
    max_students
};

constexpr auto operator+(StudentNames a) noexcept 
{
    return static_cast<std::underlying_type_t<StudentNames>>(a);
}

namespace Students
{
    enum Names 
    {
        kenny,
        kyle,
        stan,
        butters,
        cartman,
        max_students
    };
}


namespace Animals
{
    enum Names
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };
    std::vector<int> animalLegs { 2, 4, 4, 4, 2, 0 };

}

int main() 
{
    std::vector<int> testScores(+StudentNames::max_students);
    assert(Animals::Names::max_animals == Animals::animalLegs.size());
    
    testScores[+StudentNames::stan] = 76;

    std::cout << "The class has " << +StudentNames::max_students << " students.\n";

    std::cout << "An elephant has " << Animals::animalLegs[Animals::Names::elephant]
    << " legs.\n";
    return 0;
}