#include <iostream>
#include <string>

int main() {
	std::cout << 3 + 4 << '\n';

	std::cout << 3 + 4 - 5 << '\n';

	std::cout << 2 + 3 * 4 << '\n';
	int x{ 2 };
	std::cout << "What does overwring the variable x (is declared at 2) do in the program" << '\n';
	std::cout << (x = 5) << '\n';

	std::cout << 2 + 3 << '\n';

	int uusi{ 6 };
	int y{ uusi - 2 };
	std::cout << y << '\n';

	int z{};
	z = uusi;
	std::cout << z * uusi << '\n';

	return 0;

}