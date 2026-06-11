
#include <iostream>

void performOperation(double firstValue, double secondValue, char operation)
{
	switch (operation)
	{
	case '+':
		std::cout << firstValue << "+" << secondValue << " The result is: " << firstValue + secondValue << '\n';
		break;
	case '-':
		std::cout << firstValue << "-" << secondValue << " The result is: " << firstValue - secondValue << '\n';
		break;
	case '*':
		std::cout << firstValue << "*" << secondValue << " The result is: " << firstValue * secondValue << '\n';
		break;
	case '/':
		if (secondValue != 0)
			std::cout << firstValue << "/" << secondValue << " The result is: " << firstValue / secondValue << '\n';
		else
			std::cout << "Error: Division by zero is not allowed.\n";
		break;
	default:
		std::cout << "Error: Invalid operator.\n";
	}
}

double askUserNumber()
{
	std::cout << "Enter a double value\n";
	double value{};
	std::cin >> value;
	return value;
}

int main()
{
	double firsrtValue{ askUserNumber() };
	double secondValue{ askUserNumber() };

	std::cout << "Enter an operator (+, -, *, /)\n";
	char operation{};
	std::cin >> operation;
	performOperation(firsrtValue, secondValue, operation);
	return 0;

}
