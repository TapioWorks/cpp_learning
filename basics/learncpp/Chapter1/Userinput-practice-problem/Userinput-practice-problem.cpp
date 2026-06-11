#include <iostream>

int main() {
	int num1{};
	int num2{};
	int num3{};

	std::cout << "Please enter three numbers: " << '\n';

	std::cout << "First number: ";
	std::cin >> num1;
	std::cout << "Second number: ";
	std::cin >> num2;
	std::cout << "Third number: ";
	std::cin >> num3;

	std::cout << "The numbers you entered are: " << num1 << ", " << num2 << ", and " << num3 << '\n';
	return 0;
}