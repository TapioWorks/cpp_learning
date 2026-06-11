#include <iostream>
#include "doMathFunctions.h"

void doMath(int mathNum1, int mathNum2)
{
	std::cout << mathNum1 << " + " << mathNum2 << " = " << mathNum1 + mathNum2 << "\n";
	std::cout << mathNum1 << " - " << mathNum2 << " = " << mathNum1 - mathNum2 << "\n";
	std::cout << mathNum1 << " * " << mathNum2 << " = " << mathNum1 * mathNum2 << "\n";
}