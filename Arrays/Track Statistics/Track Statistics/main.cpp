#include <iostream>
#include <string>

#include "Stats.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void getData(Stats& runner, string& name, double time);
void createReport(Stats runner, string& fastest, string& slowestPerson);

int main()
{
	Stats runner;
	
	string name;
	double time;
	int capacity = 0;
	string fastestPerson;
	string slowestPerson;

	cout << "Regional Track Statistics - 100 Yard Dash" << endl;
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		if (runner.checkArray(capacity))
		{

			cout << "Enter the runner's name: ";
			cin >> name;
			cout << "Enter the runner's time: ";
			cin >> time;
			while (time < 0)
			{
				cout << "Time cannot be negative. Please enter a valid time: ";
				cin >> time;
			}
			cout << endl;
			getData(runner, name, time);
		}

	}
	createReport(runner, fastestPerson, slowestPerson);

	system("pause");
}

void getData(Stats& runner, string& name, double time)
{
	runner.setName(name);
	runner.setDashTime(time);
}

void createReport(Stats runner, string& fastestPerson, string& slowestPerson)
{
	double average = 0;
	double fastestTime;
	double slowestTime;

	average = runner.getAverage();
	fastestTime = runner.getFastest(fastestPerson);
	slowestTime = runner.getSlowest(slowestPerson);

	cout << endl;
	cout << "Track Statistics - 100 Yard Dash" << endl;
	cout << endl;
	cout << "Average 100 yard-dash time: ";
	cout << average << " seconds" << endl;
	cout << "Fastest Runner: " << fastestPerson << " ran it in " << fastestTime << " seconds" <<  endl;
	cout << "Slowest Runner: " << slowestPerson << " ran it in " << slowestTime << " seconds" << endl;


}