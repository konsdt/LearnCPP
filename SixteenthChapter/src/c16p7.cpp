#include <iostream>
#include <vector>
#include <string>
#include <ranges> //c++20



/*
16.7 Range-based for loops (for-each)
Range based for loops work for all common array types in c++ (std::array, std::vector
C-style arrays)
"Best practice:" Favor Range based for-loops when traversing containers.
the variable "num" is assigned the the value of the array element, meaning
this could be expensive for some types
"Best practice:" Use type deduction (auto) with range based for-loops to have 
the compiler deduce the type of the array element.
"Best practice:" In range-based for-lopps, the element declaration should use
a (const) reference whenever you would normally pass that element type by (const)
reference.

"Tip": If using type deduction in a ranged-based for-loop, consider always using
const auto& unless you need to work with copies. This will ensure copies aren't
made even if he element type is later changed.

Traversing an array in reverse had to be done with indexing prior to c++20
But c++20 includes some utility to create a reverse view of an array that
can be used in a range base for loop to traverse it from the end to the front

*/

template <typename T>
bool isValueInArray(const std::vector<T>& array, const T& value)
{
    for (const auto& element : array)
    {
        if (element == value)
        {
            return true;
        }
    }   
    return false;
}


int main()
{
    using namespace std::literals; // for s suffix for std::string literals
    std::vector words { "peter"s, "likes"s, "frozen"s, "yogurt"s };
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (auto num : fibonacci)
        std::cout << num << ' ';
    std::cout << '\n';

    // by making the element declaration in the range-based loop a const ref
    // we can avoid making copies of the expensive std::strings
    for (const auto& word : words)
        std::cout << word << ' ';
    std::cout << '\n';

    for (const auto& word : std::views::reverse(words))
        std::cout << word << ' ';
    std::cout << '\n';

    std::vector names { "Alex"s, "Betty"s, "Caroline"s, "Dave"s, "Emily"s, "Fred"s, 
                        "Greg"s, "Holly"s};

    std::string new_name { "???" };
    std::cout << "Enter a name: ";
    std::cin >> new_name;

    bool found {false};
    for (const auto& name : names)
    {
        if (name == new_name)
        {
            std::cout << new_name << " was found.\n";
            found = true;
            break;
        }
    }   
    if (!found)
        std::cout << new_name << " was not found.\n";
    
    std::cout << '\n';


    bool found2 { isValueInArray(names, new_name)};
    if (found2)
        std::cout << new_name << " was found.\n";
    else
        std::cout << new_name << " was not found.\n";

    std::cout << '\n';
    return 0;
}