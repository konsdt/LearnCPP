#include <iostream>
#include <vector>
#include <string>


/*
16.10 std::vector and stack behavior

This section treats situations where the number of elements to be entered is 
truly not known ahead of time, there is a better approach.

Stack:
works with last-in, first-out (LIFO) principle (stack like in recursive functions,
a call puts a funtion on the call stack and a return removes it from the call stack)
This is implemented with two operations:
 - push: pushes new element on top of stack
 - pop: returns removed element or void
additional:
 - top/peek: get the top element on the stack
 - empty: does the stack have elements
 - size: number of elements on the stack

In C++ stack-like operations are added to library container classes that 
allow for efficient insertion or removal of elements. (std::vector, std::deque,
std::list)

Stack behavior with std::vector:
 - push_back(): put new element on top of stack
 - pop_back(): remove the top element from the stack
 - back(): top or peek
 - emplace_back(): alternate from push_back() that can be more efficient


The reserve() member function of std::vector has the ability to change the 
capacity (but not the length like resize or bracket() init does)

emplace_back() is more efficient when a temporary object is created that we
want to only create to push it on the stack

*/

struct Foo
{
    std::string a{};
    int b{};
};

void printStack(const std::vector<int>& stack)
{
    if (stack.empty())
        std::cout << "Empty.";
    
    for (auto element : stack)
        std::cout << element << ' ';
    
    std::cout << "\tCapacity: " << stack.capacity() << " Length " << stack.size()
    << '\n';
}

int main()
{
    std::vector<int> stack{};

    printStack(stack);

    stack.push_back(1);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    std::cout << "Top: " << stack.back() << '\n';

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    std::vector<Foo> stack2{};

    //When we already have an object, push_bacl and emplace_back are the same
    Foo f{"a", 2};
    stack2.push_back(f);
    stack2.emplace_back(f);

    //when creating a temporary argument emplace_back is more efficient
    stack2.push_back({"a", 2}); // creates a temporary arguments, then copies it
    // into the vector
    //stack2.emplace_back({"a", 2}); // forwards the arguments so the object can be
    // created directly in the vector (no copy mode)

    //does not work prior to c++20
    // for me it doesnt work with c++20 either
    return 0;
}