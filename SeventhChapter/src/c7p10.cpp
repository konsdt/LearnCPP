#include<iostream>

// 7.10 Break and continue
// "break" causes any loop to end and the code execution continues with whatever
// statement comes after the loop
// "continue" ends the current iteration of the loop without ending the entire
// loop
// /Best Practice/: Only use Break and continue if they simplify the loop logic
// and not if they cause hard to follow jumping.
// Similar Best Practice holds for "early return" statements. Many people argue
// that they should be avoided entirely, but the can be used if they simplify
// the functions logic by a lot.
//
// 7.11 Halts (exiting your program early)
// there are several different halts with different properties, still they should 
// almost never be used! This is because none of them clean up local variabels!
// Exceptions are a better and safer method for handling error cases
//
// 7.12 Introduction to testing your code
// /Best Practice/: Write your proram in small, well defined units (functions 
// or classes), compile often, and test your code as you go.
// Types of testing:
// "Informal testing":
// write some code to test the unit that was just added and then remove it 
// after successful testing.
// "Preserving your test":
// move the temporery test code to a test function, if you want to test you
// can simply call the tests, also new test cases can easily be added and old
// ones are not lost
// "Automating your test functions":
// write test functions that contain both the test and the expected answers, and
// compares them. This will then allow to call the test function at any time to 
// see if you broke something
// "integration testing":
// testing if the integration of the units was successful. This can be more 
// challenging
//
// 7.13 Code coverage
// this term describes how much of the source code is executed while testing
// "Statement coverage": percentage of statements exercised by the testing routine
// 100% Statement coverage is good but not enough to ensure correctness
// "Branch coverage": Every branch in execution flow 
// /Best practice/: Aim for 100% branch coverage of your code.
// "loop coverage": informally called 0, 1, 2 test: you should ensure that the
// loop works properly when it iterates 0 times 1 time and 2 times
// "Testing categories of input":
// for integers: make sure how the function handles negative, 0 and positive values
// for floating: test values that have precision issues (sligthly larger: -0.1, 0.1 and 
// slightly smaller -0.6 and 0.6)
// for strings: empty string, normal valid strings, strings that have whitespace and
// strings that are all whitespace
// for pointers: check nullptr
//
// 7.14 Common semantic errors in c++
// * incorrectly code contidional operators
// * infinite loops
// * off-by-one errors
// * incorrect operator precedence
// * precision issues with floating point types
// * integer division
// * accidental null statements (; behind an if condition)
// * not using compound/block statements when requiered (after conditionals)
//
// 7.15 Detecting and handling errors
// "Handling the error within the function":
// "passing errors back to the caller": only possible if not entire return value
// range is needed
// "Fatal errors": case for a halt statement
// "Exceptions": are a separate way to pass errors back to the caller
// -> propagates up until main() if not caught and then will terminate the program
//
// 

int main()
{
    
    return 0;
}
