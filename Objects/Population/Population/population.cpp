#include "population.hpp"

Population::Population()
{
	population = 0;
	births = 0;
	deaths = 0;
}

Population::Population(int pop, int birth, int death)
{
	population = pop;
	births = birth;
	deaths = death;
}

void Population::setPopulation(int pop)
{
	population = pop;
}

void Population::setDeaths(int death)
{
	deaths = death;
}
void Population::setBirths(int birth)
{
	births = birth;
}

double Population::getBirthRate()
{
	birthrate = (births/population);
	return birthrate;
}

double Population::getDeathRate()
{
	deathrate = (deaths/population);
	return deathrate;
}

void Population::displayStats()
{
	cout << "Population: " << population << endl;
	cout << "Births: " << births << endl;
	cout << "Deaths: " << deaths << endl;
}

Population::~Population()
{

}

