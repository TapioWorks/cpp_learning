#include <iostream>
#include "compare.h"
#include "askFromUser.h"
#include "doMathFunctions.h"

int main()
{
    std::cout << "Welcome to simple number adding and comparions app!\n";
	int firstnum{ askUserForNumber()};
	std::cout << "Please give another number\n";
	int secondnum{ askUserForNumber()};
	compare(firstnum, secondnum);
	doMath(firstnum, secondnum);
	return 0;

}
