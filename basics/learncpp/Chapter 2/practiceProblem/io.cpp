#include <iostream>
#include "io.h"

int readNumber()
{
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	return number;
}

void writeAnswer(int result)
{
	std::cout << "The result of adding the two numbers is: " << result << '\n';
}