#include <iostream>
#include "io.h"

int main()
{
    std::cout << "This is the Quiz program from the end of Chapter 2 in learncpp.com!\n";
	std::cout << "Please enter two numbers, these numbers will be added together and the result will be displayed.\n";
	int firstNumber{ readNumber() };
	int secondNumber{ readNumber() };
	std::cout << "Adding the two numbers together...\n";
	writeAnswer(firstNumber + secondNumber);
}