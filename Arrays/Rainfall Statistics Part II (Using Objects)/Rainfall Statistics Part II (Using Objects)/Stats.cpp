#include "Stats.hpp"

Stats::Stats()
{
	rainData[30] = { 0 };	//Intialize all elements to 0
}

double Stats::total()		// Calculate total sum of all rain data
{
	double total = 0;
	
	for (int i = 0; i < 12; i++)
	{
		total = total + rainData[i];
	}

	return total;
}

double Stats::average()		// Calculate average of total sum of rain data
{
	double average = 0;

	for (int i = 0; i < 12; i++)
	{
		average = average + rainData[i];
	}

	average = (average / 12);

	return average;
}

double Stats::lowest(int& lowMonth)		// Find the month with the lowest rainfall
{
	double lowest = rainData[0];

	for (int i = 0; i < 12; i++)
	{
		if (rainData[i] < lowest)
		{
			lowest = rainData[i];
			lowMonth = i;
		}
	}

	return lowest;
}

double Stats::highest(int& highMonth)		// Find the month with the highest rainfall
{
	double highest = rainData[0];

	for (int i = 0; i < 12; i++)
	{
		if (rainData[i] > highest)
		{
			highest = rainData[i];
			highMonth = i;
		}
	}

	return highest;
}

bool Stats::storeValue(double userInput)	// Store the rainfall data in array
{
	if (index < 30)
	{
		{
			rainData[i] = userInput;
			i++;
		}
		return true;
	}

	else
	{
		std::cout << "You have exceeded the storage limit" << std::endl;
		return false;
	}
}

Stats::~Stats()	// Destructor
{

}