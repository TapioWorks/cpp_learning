#include <iostream>

int main() {
	int a; // declaration of variable a
	int b = 10; // declaration and initialization of variable b
	int c(20); // declaration and initialization of variable c using parentheses
	int d{ 30 }; // declaration and initialization of variable d using braces
	int e{}; // declaration and default initialization of variable e (value will be 0)

	// This is the way you want to initialize variables in modern C++.

	int f{ 40 };

	std::cout << "Value of f is: " << f << std::endl;
	
	int width; // declaration of variable width
	width = 5; // assignment of value 5 to variable width

	std::cout << width << std::endl;

	width = 10; // reassigning a new value to variable width

	std::cout << width << '\n'; // prints 10

	std::cout << "Hello this me speaking\n";
	std::cout << "I am learning C++\n";
	std::cout << "I am enjoying it\n";

	int userInput{};
	int userInput2{};

	std::cout << "Please enter a number: ";
	std::cin >> userInput; // taking input from the user and storing it in variable userInput
	std::cout << "Please enter a  SECOND number: ";
	std::cin >> userInput2; // taking input from the user and storing it in variable userInput2

	std::cout << "You entered: " << userInput << " You also entered: " << userInput2 << '\n';
	return 0;
}