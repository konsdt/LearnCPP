#include<iostream>


/*
12.2 The stack and the heap
the memory is divided into 5 different areas:
 * code segment for code (read only)
 * bss segment for zero initialized global and static variables
 * data segment for initialized --------"-------------
 * heap for dynamically allocated variables
 * stack function parameters, local variables and other function related variables

The heap segment:
"new"-operator can be used to allocate memory in the application's heap
int* ptr { new int }; // ptr is assigned 4 bytes in the heap
sequential memory requests may not result in sequential memory addresses!
deleting allocated memory returns it to the heap and can be reused, however the
variable is not deleted!!

  - allocating memory on the heap is comparitively slow
  - allocated memory stays allocated until it is specifically deallocated or the
    application ends
  - dynamically allocated memory must be accessed through a pointer and dereferencing
    a pointer is slower than accessing a variable directly
  - the heap is a big pool of memory and therefore big objects like large arrays,
    structures or classes can be allocated there

The call stack:
keeps track of all the active functions (called and not yet terminated) and handles
all function parameters and local variables

The stack data structure:
a data structure is a programming mechanism to organize data in a way, so it can be
used efficiently. e.g.: arrays and structs that we already know
a stack is one of those and it is limited in the following way:
 1. Look at top item of the stack (top())
 2. Take the top item off the stack (pop())
 3. Put a new item on top of the stack (push())
(Plate analogy)

The call stack in action:
 1. The program encounters a function call
 2. A stack frame is constructed and pushed on the stack
    stack frame:
    * address of instruction beyond the function call (return address) this allows
    the cpu to return to the correct point of execution after the function call
    * all function arguments
    * memory for any local variables
    * saved copies of any registers (stack pointers) modified by the function 
      that need to be restored when the function returns
 3. The cpu jumps to the functions start point
 4. functions instructions begin executing
    when it terminates:
    a) Registers are restored
    b) stack frame is popped off the stack -> frees memory
    c) return value is handled
    d) cpu returns execution at return address

Remeber from this: Functions are pushed on stack during execution and popped off
it afterwards. 

Advantages and Disadvantages:
 * allocating mem is fast
 * mem is in scope as long as it is on the stack
 * mem is known at compile time
 * relatively small

Stack overflow

*/

int g_counter{ 0 };

void eatStack()
{
    std::cout << ++g_counter << ' ';

    // We use a conditional here to avoid compiler warnings about infinite recursion
    if (g_counter > 0)
        eatStack(); // note that eatStack() calls itself

    // Needed to prevent compiler from doing tail-call optimization
    std::cout << "hi";
}

int main()
{
    eatStack();

    return 0;
}