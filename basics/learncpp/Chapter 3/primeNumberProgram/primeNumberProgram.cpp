
#include <iostream>

bool isPrime(int number)
{
	if (number == 2)
	{
		return true;
	}
	else if (number == 3)
	{
		return true;
	}
	else if (number == 5)
	{
		return true;
	}
	else if (number == 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
    std::cout << "Please give a number between 0 - 9\n";
	int userInput{};
	std::cin >> userInput;
	std::boolalpha;
	if (isPrime(userInput))
		std::cout << userInput << " is a prime number.\n";
	else
		std::cout << userInput << " is not a prime number.\n";
    return 0;
}
