#include <iostream>
#include <string>


// 9.9 Pass by address
// Pass by address does not make a copy of the object being pointed to
// thus just like pass by refrence, passs by address is fast, and it avoids making
// a copy of the argument object
// Pass by address allows the function to modify the argument's value
// if a function is not supposed to modify the object bing passed in , the function 
// parameter can be made a pointer to const: void changeValue(const int* ptr){}
// when passing a parameter by address, care should by taken to ensure the pointer is not
// a null pointer. When this null pointer is dereferenced in the boidy of the function,
// undefined behavior results. This can be done by testing whether the function 
// parameter is null as a precondition (like below)
// if a null ptr should never be passed an assert can be used instead
// "Best practice": Prefer pass by refrence to pass by address unless you have a specific
// reasion to use pass by address.
void print(int* ptr)
{
    if (!ptr)
        return; // if ptr is a null pointer, early return back to the caller
                //
        // if we reached this point, we can assume ptr is valid
        // so no more testing or nesting required
    std::cout << *ptr;
}


void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr = 6;
}

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference
{                                             // holds the address of str
    std::cout << ref << '\n';
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer
{                                           // that holds the address of str
    std::cout << *ptr << '\n'; // print the value via the dereferenced ptr
}

int main()
{
    std::string str{ "Hello, world!" };
    
    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    int x{ 5 };
    std::cout << "x = " << x << '\n';
    changeValue(&x); // we are passing the address of x to the function
    std::cout << "x = " << x << '\n';
    
    print(&x);

    return 0;
}
