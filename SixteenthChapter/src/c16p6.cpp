#include <iostream>
#include <vector>

/*
16.6 Arrays, loops, and sign challenge solutions
Very confusing and cluttered options to traverse arrays using indices.
Therefore the best option is:
"Best practice:" Avoid array indexing with integral values whenever possible.
Use range based for loops or iterators!
One of the very cluttered exmples follows now:
*/

//signed counterpart of std::size_t to avoid wrap around problems
using Index = std::ptrdiff_t;

constexpr std::size_t toUZ(Index value)
{
    return static_cast<std::size_t>(value);
}

int main() 
{
    std::vector arr{ 9, 7, 5, 3, 1 };

    auto length { static_cast<Index>(arr.size()) }; // in c++20 prefer std::ssize
    for (auto index {length-1}; index >= 0; --index)
        std::cout << arr[toUZ(index)] << ' ';

    return 0;
}