#include <iostream>

#define PROJECT_NAME "Functions"

/*
12.1 Function Pointers
functions have their own l-value function type!
functions also live at assigned addresses
syntax for creating a non-const function ponter is on of the ugliest there is in
C++
int (*fcnPtr)();
like this it is a pointer that points to a function that returns an integer and
has no parameters
there is implicit dereference with most modern compilers when calling the function
this is what one would expect anyway since, function names are nothing but pointers
to functions anyway
Intersting Note: default parameters do not work with function pointers since default
parameters are resolved at comile time but function pointers are only reselved at
run-time

Passing functions as arguments to other functions or "Callback functions":
this is one of the most useful things one can do with function pointer,
pass them as arguments to other functions
example here: sorting algorithm, they iterate through a list of numbers does comparisons
and reorders list on basis of comparisons results. Therefore by varying the
comparison function one can change how the algorithm orders the numbers without
changing any of the rest of the functions. 
*/

int foo() {
    return 5;
}

int goo() {
    return 6;
}

int main() {
    int (*fncPtr)(){ &foo }; //fcnPtr points to function foo
    fncPtr = &goo; // fcnPtr now points to function goo     
    return 0;
}
