#include <iostream>
#include <string>
#include <string_view>

// 9.10 Pass by address (part 2)
// One of the most common uses to use pass by address is to allow a function
// to accept an "optional" argument.
// but in many cases function overloading is a better alternative to achieve
// the same result
//
// 

// version of greet with optional nullptr argument
void greet(std::string* name=nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';
}

// overloading as alternative to optional nullptr object
void greet2(std::string_view name)
{
    std::cout << "Hello " << name << '\n';
}

void greet2()
{
    greet2("guest");
}


// Changing what a pointer parameter points to, when we pass an adress to a function
// the address is copied, thus any changes to the address are only done to the copy
// and will not change what the original address was pointing to

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2)
{
    ptr2 = nullptr; // make the function parameter a null pointer
}


int main()
{
    greet(); // we do not know who the user is yet

    std::string joe{ "joe" };
    greet(&joe); // we know the user is joe

    greet2();
    greet2(joe);


    int x{5};
    int* ptr{ &x }; // ptr points to x
                    //
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);
    
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    return 0;
}
