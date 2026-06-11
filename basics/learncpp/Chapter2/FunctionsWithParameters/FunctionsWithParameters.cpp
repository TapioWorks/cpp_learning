#include <iostream>
#include "app.h"
int doMath(int first, int second, int third, int fourth);

int doubleNumber(int numberToDouble)
{
	return numberToDouble * 2;
}

int doMath(int first, int second, int third, int fourth)
{
	return first + second * third / fourth;
}

int main() {

	std::cout << "Enter a number to double: ";
	int userNumber;
	std::cin >> userNumber;
	std::cout << "The number you have was: " << userNumber << " and the double of that number is: "
		<< doubleNumber(userNumber) << '\n';
	int number1 = { 10 }, number2 = { 10 }, number3 = { 10 }, number4 = { 10 };
	std::cout << "The result of the math function is: " << doMath(number1, number2, number3, number4) << '\n';
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
	return 0;
}