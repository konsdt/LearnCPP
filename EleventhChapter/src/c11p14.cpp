#include<iostream>
#include<cassert>
/*
11.14 Void pointers
Also known as generic pointer can point at any object of any data type, it is 
declared by using the void keyword as the pointers type.
Since it does not have a type dereferencing it is illegal.
Before dereferencing it it must be explicitly converted to the correct type.
Should generally be avoided since there are much better ways to handle
multiple data types like e.g. templates or function overloading

11.15 Pointers to pointers and dynamic multidimensional arrays
It is exactly what one would expect: a pointer to a pointer
This can be used to dynamically allocate more than 1 dimensional arrays
in loops
This though very quickly gets very tricky and difficult and is generally 
not recommended, thus it should be avoided whenever possible

*/

enum class Type
{
    tInt,
    tFloat,
    tCstring
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
        case Type::tInt:
            std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
            break;
        case Type::tFloat:
            std::cout << *static_cast<float*>(ptr) << '\n';
            break;
        case Type::tCstring:
            std::cout << static_cast<char*>(ptr) << '\n';
            // std::cout will treat char* as a c-style string, therefore we 
            // should not perform indirection (dereferencing in this case)
            break;
        default:
            assert(false && "type not found");
            break;
    }
}


int main()
{
    int nValue { 5 };
    float fValue { 7.5f };
    char szValue[] { "Mollie" };

    printValue(&nValue, Type::tInt);
    printValue(&fValue, Type::tFloat);
    printValue(szValue, Type::tCstring);


    return 0;
}
