//include in and output header
#include <iostream>

//as a side note: one should abstain from defining variable globally(accesible to all functions)
//rather move to define them inside the respective function from now on

int main() {
	//define uninitialized variable x
	int x;
	int y;
	//Lets see what random number we get from ram
	std::cout << "Print random number at location of x: " << x << " and " << y << '\n';
	// mby the meson compiler is to smart and automatically initializes to 0
	// it prints 0 for x and y
	// it also issues a warning about the uninitialized variables
	// one should always avoid situations with undefined behavior -> initialize ur variables
	
	return 0;
	
}
