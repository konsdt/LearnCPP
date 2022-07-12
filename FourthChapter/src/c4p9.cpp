#include <iostream>

// 4.9  Boolean variables 
// can only have two values true or false


int main() 
{
    bool b1 { true };
    bool b2 { !false }; //will be initialized with the value true since ! is the
                        //NOT operator

    b1 = false;
    bool b3 {}; // default initialize to false
    
    // std::cout evaluates false and true to 0 and 1
    std::cout << b1 << "\n";
    std::cout << b2 << "\n";
    std::cout << b3 << "\n";
    // std::boolalpha can be used to actually output the words:
    std::cout << std::boolalpha;
    std::cout << b1 << "\n";
    std::cout << b2 << "\n";
    std::cout << b3 << "\n";
    // to tur it back off:
    std::cout << std::noboolalpha;
    

    //input Bools:
    //
    bool b {};
    std::cout << "Enter a boolean value: ";

    std::cin >> std::boolalpha;
    std::cin >> b;

    std::cout << "You entered: " << b << "\n";
    
    
    return 0;
}
