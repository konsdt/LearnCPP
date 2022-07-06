#include <iostream>

// 2.10 Preprocessor
// Before compilation every code file is translated, a translated file is called
// translation unit
// The preprocessor is the most notworthy translator program
// it looks for its directives that start wit "#" and do not end with a semicolon
// 
// 1. includes
// #include <iostream>
// the preprocessor replaces the include with the contents of the included file
// 
// 2. Macro defines
// a macro is a rule that defines how input text is converted into replacement
// output text
//  a) function-like macros (dangerous, cant do more than normal function)
//  b) object-like macros
//     * #define identifier
//     * #define identifier substitution_text
//  With substitution_text: the preprocessor replaces any further occurence of
//  the identifier with the substitution_text
// used back in C to assign names to literals, this should be avoided since there
// are better methods now, should only be found in legacy code and generally be
// avoided
// Macros without substitution text replace the identifier with nothing. These
// in contrast are typically considered acceptable to use
// 
// 3. Conditional compilation
// Allow to specify under what conditions code will compile or wont compile
// there are lost but 3 most used: #ifdef, #ifndef, #endif
// 
// Macros only cause text substitution in code not in other preprocessor directives

// Scope of Defines:
// Functions and thus local scope does not exist for direvtives
// In multifile projects directives will only work filewise, not visibel for 
// linker
#define MY_NAME "Konstantin"

#define PRINT_JOE


int main()
{
    std::cout << "My name is " << MY_NAME << "\n"; 
    
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB // alternative syntax: #if defined PRINT_BOB
    std::cout << "Bob\n"; // will not be compiled since PRINT_BOB is not defined
#endif

#ifndef PRINT_MAX //alternative syntax: #if !defined PRINT_MAX
    std::cout << "Max\n"; // will not be compiled since PRINT_MAX is not defined
#endif

// another usefull conditional compilation:
#if 0 // Dont compile anything starting here -> very usefull to comment out
      // multiple lines

#endif

    return 0;
}
