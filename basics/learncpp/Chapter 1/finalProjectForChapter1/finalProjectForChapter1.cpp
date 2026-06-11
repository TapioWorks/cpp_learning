#include <iostream>

int main() {
	int firstNumber{}, secondNumber{};

	std::cout << "Enter the first number: ";
	std::cin >> firstNumber;

	std::cout << "Enter the second number: ";
	std::cin >> secondNumber;

	std::cout << "The sum of " << firstNumber << " and " << secondNumber << " is: "
		<< (firstNumber + secondNumber) << '\n';

	return 0;
}