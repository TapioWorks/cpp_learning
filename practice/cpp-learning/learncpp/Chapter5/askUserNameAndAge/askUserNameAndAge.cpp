#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name\n";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter your age\n";
	int age{};
	std::cin >> age;

	int nameLength{ static_cast<int>(name.length()) };

	std::cout << "Your age + name length is " << age + nameLength << '\n';
	return 0;
}
