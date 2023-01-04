#include <iostream>
#include <string>
// 10.9 Member selection with pointers and references
// References act just like the object itself thus we can use the member selector
// operator "." on a reference of a struct aswell
//

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee( const Employee& e)
{
    // Use member seklection operator (.) to select member from reference to struct
    std::cout << "Id: " << e.id << "\n";
    std::cout << " Age: " << e.age << "\n";
    std::cout << " Wage " << e.wage << "\n";
}

// but the member selection with (.) does not work if you have a pointer to a struct
// since it would have first to be derefernced from the address
// the syntax would look like the following
// Employee joe {1, 34, 65000.0};
// Employee* ptr{ &joe};
// (*ptr).id    // this is a little ugly since we need to enforce precedence of
// the dereferencing by using the paranthesis
// therefore c++ offers a special member selection operator for pointers which
// does the dereferencing implicitly
//
// "Best practice": When using a pointer to access the value of a member, use the 
// member selection from pointer operator (->) instead of the mmber selection operator (.).

// in some cases pointers and non-pointer variables can be mixed which leads
// to both dereferening operators being used in succesion, example:
//
struct Paw
{
    int claws {};
};

struct Animal
{
    std::string name {};
    Paw paw {};
};

int main()
{
    Employee joe { 1, 34, 65000.0 };
    
    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);
    
    Employee* ptr { &joe };

    std::cout << ptr->id << "\n"; // Better: use -> to select member from pointer to object

    //mixing both types of dereferencing operators
    Animal puma { "Puma", { 5 }};

    Animal* ptr1 { &puma };

    //ptr is a pointer, use ->
    //paw is not a pointer, use .

    std::cout << (ptr1->paw).claws << "\n";

    return 0;
}
