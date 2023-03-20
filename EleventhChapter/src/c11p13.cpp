#include<iostream>
#include<string>

/*
11.13 For-each loops

####
for (element_declaration : array)
    statement;
####
a loop that iterates through each element in an array assigning the value of
the current array element tot the variabel declared in "element_declaration"

this is an ideal case in which to use the auto keyword and let cpp deduce the 
type for "element_declaration"

"Best practice": In for-each loops element delcarations, of your elements are 
non-fundamental types, use references or const references for performance.

For each-loops also work with many other kinds of list-like structures (not only
fixed arrays) e.g. std::vector.

For-each has to know the lenght of an array, therefore it does not work with 
only a pointer to an array, like if the array decays to a pointer when handed
to a function. For the same reason it does not work with dynamic arrays.

For each-loops do not provide a direct way to access the current index of the 
respective element. Since C++20 they allow for an init-statement which makes it
possible to count up by yourself.
####
for (init-statement; element-declaration : array)
    statement;
####

*/

int main()
{

    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci)
    {
        std::cout << number << " ";
    }
    
    std::cout << '\n';
    
    // in the above loop every element is copied to the variable number in turn
    // for more complicated types this can become quite costly, therefore we
    // can use references in a for-each loop

    std::string array[]{ "peter", "likes", "frozen", "yogurt" };
    for (auto& element : array)
    {
        std::cout << element << " ";
    }
    // if we want to use the elements as read only one should use const reference "const auto& element"

    std::cout << '\n';

    std::string names[] { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
    
    std::string new_name {};
    std::cout << "Enter a name:";
    std::cin >> new_name;
    bool name_not_found { true };

    for (const auto& listname : names)
    {
        if (listname == new_name)
        {   
            name_not_found = false;
            std::cout << new_name << " was found.";
            break;
        } 
    }
    if (name_not_found)
    {
        std::cout << new_name << " was not found.";
    }



    
 
    return 0;
}