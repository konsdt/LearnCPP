#include<iostream>


//9.12 Type deduction with ponters, references and const
// type deduction using the auto keyword drops the const qualifiers
// in addition to that it will also drop references
// if we want it to be a reference it needs to by reapplied like in the case of
// the const qualifier
// Top level const and low level const:
// A top-levle const is a qualifier that applies to an object itself:
// const int x; const applies to x, so it is top-level
// int* const ptr; const applies to ptr, s it is top-level
// In contrast a low-level const qualifier apples to the object being referenced or
// pointed to
// const int& ref; this applies to the oject being referenced
// const int* ptr; this const applies to the object bing pointed to
// while a const for a reference will always be low-level a pointer can have both
// a low-level and a top-level const qualifier
// when we say auto drops the const it will only drop top-level consts, low-level
// consts are not dropped
//
// if the initializer is a reference to const, the reference is dropped first, and then
// any top-lvele const is dropped from result
// "Best practice": If you want a const reference, reapply the const qualifier even
// when it is not strictly necessary, as it makes your intent clear and helps 
// prevent mistakes.
//
// in contrast to references, pointers are not dropped by the auto keyword
// "Best practice": If you want a const pointer, reapply the const qualifier even ehen it 
// is not strictly necessary, as it makes your intent clear and helps prevent mistakes.
int main()
{

    
    return 0;
}
