#include <iostream>

int main() {
	int firstNumber{}, secondNumber{};

	std::cout << "Enter a number and the number to multiply that number with: " << '\n';

	std::cout << "First number: ";
	std::cin >> firstNumber;

	std::cout << "Second number: ";
	std::cin >> secondNumber;

	int result = firstNumber * secondNumber;

	std::cout << "The result is: " << result << '\n';

	std::cout << "And you did not ask but the triple of the first number is: " << (firstNumber * 3) << '\n';

	return 0;
}