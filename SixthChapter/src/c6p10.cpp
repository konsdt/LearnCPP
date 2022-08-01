#include<iostream>

// 6.10 Static local variables
// term "static" can be very confusing, since it can mean different things in
// different contexts
// * global variables have static duration: they are created when the program
// starts and are destroyed when it ends
// * the static keyword gives a global variable internal linkage
// Now for LOCAL variables:
// Local variables have automatic duration: created at definition, destroyed
// when the block ends
// * the static keyword gives a local variable static duration:
// created when the program starts and destroyed when it ends, therefore it will
// keep its value even after it goes out of scope
// it is common to prefix static variable with an "s_"
// Most common use case for static local variables is to create unique ids
// this id done to identify objects again later on

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; //makes a copy of the variable and returns it, while the
                       //actual variable is incremented by 1
}

// static local variables can be made constant, this helps if a very expensive
// object needs to be initialized at the beginning of a function, but it does not
// change later on, thus you can make it static so it will only be initialized once
// even though the function is called multiple times
// /Best practice/: Avoid the use of static local variables unless the variable
// never needs to be reset.




void incrementAndPrint()
{
    int value{ 1 }; //value is created here
    ++value;
    std::cout << value << '\n';
} //value is destroyed here

void staticIncrementAndPrint()
{
    static int s_value{ 1 }; //value is created here
    ++s_value;
    std::cout << s_value << '\n';
} //value is not destroyed here, but becomes inaccessible because it goes out 
  //of scope


int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();
    staticIncrementAndPrint();
    staticIncrementAndPrint();
    staticIncrementAndPrint();
    return 0;
 }
