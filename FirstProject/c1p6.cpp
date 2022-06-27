//include in and output header
#include <iostream>

// as a side note: one should abstain from defining variable globally(accesible 
// to all functions)
// rather move to define them inside the respective function from now on

int main() {
	//define uninitialized variable x
	int x;
	int y;
	//Lets see what random number we get from ram
	std::cout << "Print random number at "
                 "location of x: " << x << " and " << y << '\n';
    
	// mby the meson compiler is to smart and automatically initializes to 0
	// it prints 0 for x and y
	// it also issues a warning about the uninitialized variables
	// one should always avoid situations with undefined behavior 
    // -> initialize ur variables
	
	//1.7
	// Best practice identifier naming (variable name, function, type, other 
    // kind of item):
	
	// variable names should begin with lower case letter
	int value;
	
	// functions also start with lower case letter
	// There are two common cases for multiworded funtions variables:

	// snakecase
	int my_variable_name;
	//camelCase
	int myVariableName;
	
	// variable names that start with an underscore are usually reserved for OS
    // , library and compiler use
	
	//1.8
    // brackets and whitspace handling..
    // lines shouldnt be longer than 80 characters -> gray line
    // I need to fix my colorscheme.. onedark rn
    
    // line split at operator -> place operator on next line
    std::cout << 3 + 4
        + 5 + 6
        * 7 * 8;
    // generally align simliar things like equal signs or comment slashes
       
	return 0;
	
}
