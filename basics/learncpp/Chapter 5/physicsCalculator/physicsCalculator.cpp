/* == = Mini Physics Calculator == =

Choose an option :
1) Calculate Speed
2) Calculate Distance
3) Calculate Kinetic Energy
0) Exit

Enter choice :
*/

#include <iostream>

constexpr double kineticEnergyFactor{ 0.5 };
constexpr int exitOption{ 0 };
constexpr int speedOption{ 1 };
constexpr int distanceOption{ 2 };
constexpr int kineticEnergyOption{ 3 };

void mainMenu()
{
	std::cout << "== = Mini Physics Calculator == =\n\n";
	std::cout << "Choose an option :\n";
	std::cout << "1) Calculate Speed\n"
		<< "2) Calculate Distance\n"
		<< "3) Calculate Kinetic Energy\n"
		<< "0) Exit\n\n";
	std::cout << "Enter choice : ";
}

double askNumberFromUser(const std::string& prompt)
{
	std::cout << prompt;
	double number{};
	std::cin >> number;
	return number;
}

double calculateSpeed(double distance, double time)
{
	return distance / time;
}

double calculateDistance(double speed, double time)
{
	return speed * time;
}

double calculateKineticEnergy(double mass, double speed)
{
	return kineticEnergyFactor * mass * speed * speed;
}

void handleCalculation(int choice)
{
	switch (choice)
	{
		case speedOption:
		{
			double distance{ askNumberFromUser("Enter distance (in meters) : ") };
			double time{ askNumberFromUser("Enter time (in seconds) : ") };
			double speed{ calculateSpeed(distance, time) };
			std::cout << "Speed is " << speed << " m/s\n";
			break;
		}
		case distanceOption:
		{
			double speed{ askNumberFromUser("Enter speed (in m/s) : ") };
			double time{ askNumberFromUser("Enter time (in seconds) : ") };
			double distance{ calculateDistance(speed, time) };
			std::cout << "Distance is " << distance << " meters\n";
			break;
		}
		case kineticEnergyOption:
		{
			double mass{ askNumberFromUser("Enter mass (in kg) : ") };
			double speed{ askNumberFromUser("Enter speed (in m/s) : ") };
			double kineticEnergy{ calculateKineticEnergy(mass, speed) };
			std::cout << "Kinetic Energy is " << kineticEnergy << " Joules\n";
			break;
		}
		case exitOption:
		{
			std::cout << "Exiting...\n";
			break;
		}
		default:
		{
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}
	}
}

int main()
{
	mainMenu();
	int userChoice{};
	std::cin >> userChoice;
	handleCalculation(userChoice);
	return 0;
}
