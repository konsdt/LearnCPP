#include <iostream>

// multiple files can be easily managed with meson,
// one has to declare an files array by using files() 
// any subdirectory that contains the cpp files can be added by the subdir()
// command in the root meson.build file. Inside the subdir there is another 
// meson.build file which will contain the array of files generated by files()


int add(int x, int y); //forward declaration of add function
int getInteger();      //forward declaration of input function


int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
    getInteger();
    return 0;
}

