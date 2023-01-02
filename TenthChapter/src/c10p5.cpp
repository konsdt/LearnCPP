#include <iostream>


// 10.5 Introduction to structs, members and member selection
// a struct is a program-defined data type that allows to bundle mutltiple
// variables together into a single type
// in c++ a "member" is a variable,function or type that belongs to a struct or class
// the member selection operator "." can be used to access members of a struct
//
struct Employee
{
    int id {};
    int age {};
    double wage {};
}; // type definition has to be ended with a semicolon
   
// 10.6 Struct aggregate initialization
// at this point our structs with only data members will be "aggregates"
// aggregates in cpp have a rather complex definition
// but they can be initialized using a list like so
// Employee joe { 14, 32, 60000.0 };
// If a list is to short all the remaining members will be value initialized, which 
// in this case just means set to 0
// This also directly means that one can use an empty list to value initialize all
// members of a struct.
// "Const structs": variables of a struct type can be const and must be initialized
//
// One can easily run into problems when adding members to an existing struct that
// is later initialiuzed. This can lead to variables receiving initial values which 
// are intended for the neighbor variable, also the last variable will be value
// initialized, therefore:
// "Best Practice": When adding a new member to an aggregate, its safest to add it to 
// the bottom of the definition list so the initializers for other mebers dont shift.
// In c++20 there is a new way to initialize structs which is called "designated initializers"
struct Foo 
{
    int a {};
    int b {};
    int c {};
};

// assignement is also possible with an initializer list
// or also starting with c++20 with designated initializers
// jow = { .id = jow.id, .age = 33, .wage = 66000.0 };
//
//
// 10.7 Default member initialization
// using default member initilaizers (there are also other mechanisms that will 
// be covered later, struts and classes can self-initialize even when no explicit
// intitializers are provided
// explicitly provided values take precedence over default initializers
// "Best Practice": Provide a default value for all members. This ensures that your
// members will be initialized even if the variable definition does not include
// an initializer list.
// "Best Practice": If no explicit initializer values will be provided for an aggreagate,
// prefer value initialization (with an empty braces initializer) over default initialization (with no braces).

int main()
{
  
// DESIGNATED INIT C++20
    Foo example { .a{ 1 }, .b{ 2 }, .c{ 3 }};


    Employee joe;
    joe.id = 14;
    joe.age = 32;
    joe.wage = 60000.0;

    Employee frank;
    frank.id = 15;
    frank.age = 28;
    frank.wage = 45000.0;

    int totalAge { joe.age + frank.age };

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more money than Frank\n";
    else if (joe.wage > frank.wage)
        std::cout << "Frank makes more money than Jow\n";


    // Frank got a promotion
    frank.wage += 5000.0;

    // Today is Joes birthday
    ++joe.age; // use pre-increment to increment Joe's age by 1

    return 0;
}
