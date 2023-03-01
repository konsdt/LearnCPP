#include<iostream>
#include<string>
#include<string_view>

/*

11.7 std::string_view (part 2)
std::string objects are copied every time they are assigned to a different 
variabel name, this is due to the fact, that the object gives some guarantees:
 * string data is valid for lifetime of string object and cleaned up thereafter
 * string value can only be modified by string object
 * string value can be modified without affecting other objects

In contrast to that std::string_view provides a view of a string that 
is defined elsewhere

"Best practice": Prefer std::string_view over std::string and C-style strings 
when you only need read-only access to a string (inless you can not guearantee
the string being viewed will stay alive for the lifetime of the std::string_view,
in which case you should prefer std::string)
*/

/* 
Prefer std::string_view function parameters (over const std::string&)?
"Best Practice": Prefer passing strings using std::string_view (by value) instead
of const std::string&, unless your function calls other functions that require 
C-style strings ir std::string parameters.
*/

int main()
{
    /*
    std::string_view contains functions that let us modify the view of the string
    but not the original string itself
    */

    std::string_view str { "Peach" };
   
    std::cout << str << '\n';

    // Ignore the first character
    str.remove_prefix(1);
   
    std::cout << str << '\n';

    // Ignore the last two characters.
    str.remove_suffix(2);

    std::cout << str << '\n';
    
    /*
    Unlike real curtains they can not be opened up again, the only way to 
    return to the original string is to reassigning the source string to it
    again

    std::string_view and std::string do not use null terminators to mark the 
    end of a string, instead they keep track of the length
    */
    
    char vowels[]{ 'a', 'e', 'i', 'o', 'u'};

    // vowels is not null terminated. We need to pass teh length manually.
    // Because vowels is an array, we can use std::size to get its length.
    std::string_view str2 { vowels, std::size(vowels) };

    std::cout << str2 << '\n'; // This is safe. std::cout knows how to print std::string_view 


    return 0;
}