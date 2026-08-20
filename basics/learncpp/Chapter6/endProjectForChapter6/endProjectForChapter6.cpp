#include <iostream>
#include <string_view>

// Write the function getQuantityPhrase() here
std::string_view getQuantityPhrase(int number)
{
    if (number == 0)
        return "no";

    else if (number == 1)
        return "a single";

    else if (number == 2)
        return "a couple of";

    else if (number == 3)
        return "a few";

    else if (number > 3)
        return "many";

    else
        return "negative";
}

// Write the function getApplesPluralized() here
std::string_view getApplesPluralized(int number1)
{
    return (number1 == 1) ? "apple" : "apples";
}

int main()
{
    constexpr int maryApples{ 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}