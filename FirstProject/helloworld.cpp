			
#include <iostream>			//include the standar Cpp library (precompiled code, packaged for use in other code

#define PROJECT_NAME "HelloWorld"	//Meson generated this, I do not really know what its purpose is


int x;					//define a variable named x, of type int
					//variables are instantiated at runtime->created and assigned a memory address
double a;				//CPP allows the user to create their own types

					//there are different initialization methods in cpp:
int y = 5;				//copy: ok for simple data types but not preferred
int z( 6 );				//direct: faster but can not be used to init an object with e.g. a list
int t { 7 };				//brace: dissallows narrowing conversions(wrong init values for type), best practice 
					//assignements can only be done via copy.
int u { 0 };				//use this init if value is used
int v {};				//use 'value initialization' if value is temp and immediately replaced


int main() {				//Every CPP program needs a main function: Functions are a collection of iteratively executed statements
   
   std::cout << "Hello, world!"; 	//std::cout will print whatever string it is given to the command line
   std::cout << y;
   return 0;
}
