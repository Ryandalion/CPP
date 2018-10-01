#include <iostream>
#include <string>

#ifndef STATS_H
#define STATS_H

using std::cout;
using std::endl;
using std::string;

class Stats
{
public:
	Stats();

	void setDashTime(double dashtime);
	void setName(string runnerName);
	double getFastest(string& fast);
	double getSlowest(string& slow);
	double getAverage();
	bool checkArray(int capacity);

	~Stats();

private:
	double dashtime[15];
	string runnerName[15];
	string nameRunner;

	int TimeNow = 0;
	int nameIndex = 0;
	int timeIndex = 0;
	double average = 0;
};

#endif