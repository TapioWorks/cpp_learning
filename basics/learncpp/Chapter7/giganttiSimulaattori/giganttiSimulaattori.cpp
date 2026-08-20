// giganttiSimulaattori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>

void giganttiOptions()
{
    std::cout << "1) Kävele kohti kodinkone puolta\n";
    std::cout << "2) Mene katsomaan peli hyllyä\n";
    std::cout << "3) Nouda verkkokauppa tilaus\n";
    std::cout << "4) Etsi tuote kauupasta\n";
    std::cout << "0) lähde kaupasta\n";
}

void welcomeMessage()
{
    std::cout << "Terveruloa giganttiin!\n";
    std::cout << "Miten voisimme olla avauksi?\n";
}

std::string_view userChoice()
{
    std::cout << "Valitse ylläolevista vaihtoehdoista";
    int choice{};
    std::cin >> choice;
}

int main()
{
    welcomeMessage();
    giganttiOptions();


}
