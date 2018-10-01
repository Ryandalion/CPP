#include <iostream>
#include <string>

#include "population.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int birthrate;
	int deathrate;
	int population;
	int selection = 0;
	bool running = true;

	while (running != false)
	{
		cout << "Choose from the following options" << endl;
		cout << "1. Pass data by setting each field" << endl;
		cout << "2. Pass data all at once through the object" << endl;

		cin >> selection;
		if (selection == 1)
		{
			Population people;

			cout << "BIRTHRATE, DEATHRATE, POPULATION STATISTICS" << endl;
			cout << "Enter the population: " << endl;
			cin >> population;
			if (population < 2)
			{
				cout << "There must be a minimum of two people" << endl;
				population = 2;
			}
			cout << "Enter the birthrate: " << endl;
			cin >> birthrate;
			if (birthrate < 0)
			{
				cout << "Birthrate cannot be negative" << endl;
				birthrate = 0;
			}
			cout << "Enter the deathrate: " << endl;
			cin >> deathrate;
			if (deathrate < 0)
			{
				cout << "Deathrate cannot be negative" << endl;
				deathrate = 0;
			}

			people.setPopulation(population);
			people.setBirths(birthrate);
			people.setDeaths(deathrate);

			cout << endl;
			cout << "Here are the statistics: " << endl;
			cout << "Birthrate: " << people.getBirthRate() << endl;
			cout << "Deathrate: " << people.getDeathRate() << endl;
			people.displayStats();
			running = false;
		}
		if (selection == 2)
		{
			cout << "BIRTHRATE, DEATHRATE, POPULATION STATISTICS" << endl;
			cout << "Enter the population: " << endl;
			cin >> population;
			if (population < 2)
			{
				cout << "There must be a minimum of two people" << endl;
				population = 2;
			}
			cout << "Enter the birthrate: " << endl;
			cin >> birthrate;
			if (birthrate < 0)
			{
				cout << "Birthrate cannot be negative" << endl;
				birthrate = 0;
			}
			cout << "Enter the deathrate: " << endl;
			cin >> deathrate;
			if (deathrate < 0)
			{
				cout << "Deathrate cannot be negative" << endl;
				deathrate = 0;
			}

			Population people1(population, birthrate, deathrate);

			cout << endl;
			cout << "Here are the statistics: " << endl;
			cout << "Birthrate: " << people1.getBirthRate() << endl;
			cout << "Deathrate: " << people1.getDeathRate() << endl;
			people1.displayStats();
			running = false;
		}
	}
	system("Pause");

}