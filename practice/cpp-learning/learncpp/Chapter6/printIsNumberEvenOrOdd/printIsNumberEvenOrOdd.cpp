// printIsNumberEvenOrOdd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr void isEven(int number)
{
	if (number % 2 == 0)
	{
		std::cout << "The number is even\n";
	}
	else
	{
		std::cout << "The number is odd\n";
	}
}

int main()
{
    std::cout << "Please give a number\n";
	int userNumber{};
	std::cin >> userNumber;
	isEven(userNumber);
}
