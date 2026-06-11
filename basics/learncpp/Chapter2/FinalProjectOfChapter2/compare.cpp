#include <iostream>
#include "compare.h"

void compare(int num1, int num2)
{
	if (num1 > num2)
		std::cout << num1 << " is greater than " << num2 << "\n";
	else if (num1 < num2)
		std::cout << num1 << " is greater than " << num2 << "\n";
	else
		std::cout << num1 << " is equal to " << num2 << "\n";
}