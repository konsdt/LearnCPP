#include<iostream>

#define PROJECT_NAME "c2p2"

// 2.2 Function return values 
// Function needs to indicate what type of value it will return eg. int, float,
// void

// main function should return the value 0 if the program ran normally
// this return is called "exit code", "status code" or rarely "return code"
//
// exit codes can be "0", "EXIT_SUCCESS", "EXIT_FAILURE" the first two mean the
// same. The latter two are included in <cstdlib> and can alternatively be used

// Best Practive : DRY "Don't Repeat Yourself!!" This is where functions are 
// extremely usefull
// Opposite would be: WET "Write Everything Twice"

int getValueFromUser() {
    
    std::cout << "Enter any Integer: ";

    int num{ };
    
    std::cin >> num;

    return num;

}


int main() {
    // These functions will be executed at the moment of variable definition.
    int num{ getValueFromUser() };
    
    int a{ getValueFromUser() };
    int b{ getValueFromUser() };

    std::cout << a << " + " << b << " = " << a + b << "\n";

    std::cout << "Double "<< num << " is " 
        << num * 2 << "\n" ;

    return 0;

}
