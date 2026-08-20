
#include <iostream>

int main()
{
    std::cout << "Enter an integer:\n";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer:\n";
    int larger{};
    std::cin >> larger;
    if (larger < smaller)
    {
        std::cout << "Swapping the values.\n";
        int temp{ larger };
        larger = smaller;
        smaller = temp;

    }
    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';

    return 0;


}
