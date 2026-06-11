#include <iostream>

int getUserInput() {
	std::cout << "Please enter a number\n";
	int input{};
	std::cin >> input;
	return input;

}

int main() {
	int numberToMultuply = { getUserInput()};

	std::cout << "The number you gave was: " << numberToMultuply << "\n";
	std::cout << "The number doubled is: " << numberToMultuply * 2 << "\n";
	return 0;
}