#include "Stats.hpp"

Stats::Stats()
{
	dashtime[15] = { 0 };
	runnerName[15] = { "" };
}

void Stats::setDashTime(double time)
{
	dashtime[timeIndex] = time;
	timeIndex++;
}

void Stats::setName(string name)
{
	runnerName[nameIndex] = name;
	nameIndex++;
}

double Stats::getFastest(string& fastestPerson)
{
	double fastest = dashtime[0];
	int fPerson = 0;

	for (int i = 0; i < 15; i++)
	{
		if (dashtime[i] < fastest)
		{
			fastest = dashtime[i];
			fPerson = i;
		}
	}
	
	fastestPerson = runnerName[fPerson];
	return fastest;
}

double Stats::getSlowest(string& slowestPerson)
{
	double slowest = dashtime[0];
	int slowestperson = 0;

	for (int i = 0; i < 15; i++)
	{
		if (dashtime[i] > slowest)
		{
			slowest = dashtime[i];
			slowestperson = i;
		}
	}

	slowestPerson = runnerName[slowestperson];

	return slowest;
}

double Stats::getAverage()
{
	double total = 0;
	
	for (int i = 0; i < 15; i++)
	{
		total = total + dashtime[i];
	}

	average = (total/15);

	return average;
}

bool Stats::checkArray(int capacity)
{
	if (capacity > 15)
	{
		return false;
	}

	else
		return true;
}

Stats::~Stats()
{

}