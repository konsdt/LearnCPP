#include <iostream>

namespace
{
    int number_of_users { 0 };
    
    bool passOrFail()
    {
// alternatively define number_of_users here as a static
// this changes its lifetime such that its value will be safed after execution
// of the function block
        //static int number_of_users{0};
        
        ++number_of_users;
        if (number_of_users < 4)
            return true;
        else
            return false;

    }
}

int main()
{
    std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
    std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

    return 0;
}
