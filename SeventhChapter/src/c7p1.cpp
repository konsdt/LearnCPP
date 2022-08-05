#include <iostream>

// 7.1 Control flow introduction
// by default the code execution begins at top of main, executes the contained
// statements sequentially and then terminates at the end of main
// this is called the "execution path" or just "path"
// "straight line program":
// these kind of programs take the same "path" every time they run
// this is not want is wanted most of the time 
// -> "control flow statements":
// categories:
// * conditional statements: if else etc.
// * jumps: start executing statements at some other locations
// * function calls: are jumps to some other location and back
// * loops: repeat some statements x times
// * halts: quit running the program
// * exceptions: designed for error handling
//
// 7.2 If statements and blocks
// under this condition do this or do that
// /Best practice/: simply always use blocks, even if you just want to make a
// single statement conditional
// if blocks are not explicitly used, the compiler will set a blokc around the
// first statement that follows the if or else clause
// This matters when defining variables inside the conditional statements
// These have block scope and will therfore be destroyed at the end of the if 
// statement
//
// 7.3 Common if statement problems
// "Nested if statements and the danling else problem":
// else is always matched up with last unpaired if -> always use blocks so you
// avoid mixing up the else with the wrong if statement
// one should whenever possible flatten nested if statements -> restructure the 
// logic in such a way, that all is covered in one if else if and else routine
// "Null statements":
// they do nothing, usually exists when the language demands a statement but the
// programmer does not need one
// dont confuse "==" with "=" in if statements -> this mistake usually will not
// result in a compiler error
//
// 7.4 Switch statement basics
// it is possible to chain several if-else statements together, but this is both
// difficult to read and inefficient



int main() 
{
   if (x > 10)
   {
       ; // this is a null statement
   }

    return 0;
}
