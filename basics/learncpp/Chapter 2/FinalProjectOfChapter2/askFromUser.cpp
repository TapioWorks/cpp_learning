#include <iostream>
#include "askFromUser.h"

int askUserForNumber()
{
	std::cout << "Please give a number\n";
	int num{};
	std::cin >> num;
	return num;
}