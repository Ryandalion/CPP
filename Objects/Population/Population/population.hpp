#include <iostream>

using std::cout;
using std::endl;

#ifndef POPULATION_H
#define POPULATION_H

class Population
{
public:
	Population();
	~Population();

	Population(int pop, int births, int deaths);
	
	void setPopulation(int pop);
	void setBirths(int births);
	void setDeaths(int deaths); 

	void displayStats();

	double getBirthRate();
	double getDeathRate();

private:
	int population;
	int births;
	int deaths;
	double birthrate = 0;
	double deathrate = 0;
};

#endif