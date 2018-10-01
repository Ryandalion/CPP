#include "fish.hpp"

Fish::Fish()
{
	name = "";
	type = 0;
	points = 0;
}

string Fish::objectname()
{
	this->name;
	return name;
}

void Fish::setType()
{
	type = roll;
}

void Fish::setStats()
{
	if (type == 1)						// Bass
	{
		name = "Bass";
		points = 6;
	}

	if (type == 2)						// CatFish
	{
		name = "Catfish";
		points = 4;
	}

	if (type == 3)						// Old Tire
	{
		name = "Old Tire";
		points = -1;

	}

	if (type == 4)						// GoldFish
	{
		name = "Goldfish";
		points = 1;

	}

	if (type == 5)						// Octopus
	{
		name = "Octopus";
		points = 3;

	}

	if (type == 6)						// Fishing Net
	{
		name = "Fishing Net";
		points = 0;
	}
}

double Fish::totalPoints()
{
	return points;
}

void Fish::rolldice()
{
	int x = rand() % 6 + 1;
	type = x;
}

double Fish::displayPoints()
{
	return points;
}

Fish::~Fish()
{

}