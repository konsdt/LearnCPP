#include<iostream>
#include<sstream> //for std::stringstream
#include<string>

/*
12.5 Command line arguments

are optional string arguments that are passed by the operating system to the
program when it is launched

to access command line arguments inside the program a different definition of
the main function is necessary:
int main(int argc, char* argv[])

 - "argc" is an integera parameter containing a count of the number of arguments 
 passed to the program (argument count) argc will always be at least one since
 the program name itself is always the first argument
 - "argv" is where the actual argument values ar stores (argument (values) vectors)
 it is an array of char pointers (each of which points to a c-style string)
 its length is argc

Command line arguments are always passed as strings and therefore if numeric values
are passed they need to be converted to numbers...
this is a little tricky in C++

std::stringstream works a lot like std::cin, it is initialized with argv[1]
so that we can extract the integer number to an int variable by using the >> operator

When passing command line arguments, typocally straing passed in double quotes
are consideres part of the same string
it can be included in the string tho by adding a backslash

*/

int main(int argc, char* argv[]) {

    if (argc <= 1)
    {
        //On some operating systems, argv[0] can end up as an empty string instead
        //of the programs name
        //Well conditionalize our response on whether argv[0] is empty or not
        if (argv[0])
            std::cout << "Usage: " << argv[0] << " <number>" << '\n';
        else
            std::cout << "Usage: <program name> <number>" << '\n';
        return 1;
    }
    
    std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert
    // initialized with the input from argv[1]

    int myint{};
    if (!(convert >> myint)) //do the conversion
        myint = 0; //if conversion fails, set myint to a default value
    
    std::cout << "Got integer: " << myint << '\n';

    /*
    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }
    */

    return 0;
}