//include input output library header
#include <iostream>

int x{ 5 };
int y{};

//define variables a and b to hold user input (and zero-intialize it)
int a{};
int b{};


int main() {
	//std::cout is variable that allows to print characters to console; cout = character output
	//'<<' is the insertion operator
	std::cout << "Lets try this\n";
	//can also print numbers
	std::cout << 4 << '\n'; 
	//can also be used multiple times in a line
	std::cout << "Hello" << "world!\n";
	//can also print variable values
	std::cout << "value of x is " << x << '\n';
	//ask user fpr a number
	std::cout << "Enter a number:"; 
	//receive number from keyboard and store it in variable y
	std::cin >> y;
	//print number
	std::cout << "You entered " << y << '\n';
	//enter two numbers to store them in the variable a and b
	std::cout << "Enter two numbers seperated by a space:" << '\n';
	std::cin >> a >> b;
	//print them
	std::cout << "You entered " << a << " and " << b << '\n';
	// << or >> always show the direction in which the data is moving
	return 0;
}
