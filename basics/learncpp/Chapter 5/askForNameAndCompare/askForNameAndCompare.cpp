#include <iostream>
#include <string>
#include <string_view>

void compareAges(std::string_view name1, int age1, std::string_view name2, int age2)
{
	if (age1 > age2)
	{
		std::cout << name1 << "(" << age1 << ")" << " is older than " << name2 << "(" << age2 << ")" << "\n";
	}
	else if (age1 < age2)
	{
		std::cout << name2 << "(" << age2 << ")" << " is older than " << name1 << "(" << age1 << ")" << "\n";
	}
	else
	{
		std::cout << name1 << "(" << age1 << ")" << " and " << name2 << "(" << age2 << ")" << " are the same age\n";
	}
}

int askForAge(std::string_view name)
{
	std::cout << "Please enter age of: " << name << "\n";
	int age{};
	std::cin >> age;
	return age;
}

std::string askForName()
{
	std::cout << "Please enter a name\n";

	std::string name{};
	std::getline(std::cin >> std::ws, name);

	return name;
}

int main()
{
	std::string firstName{ askForName() };
	int age1{ askForAge(firstName) };

	std::string secondName{ askForName() };
	int age2{ askForAge(secondName) };

	compareAges(firstName, age1, secondName, age2);

	return 0;
}
