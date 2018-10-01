#include <iostream>
#include <string>

#include "Stats.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	Stats rainfall;
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	int lowMonth = 0;		// Index for driest month
	int highMonth = 0;		// Index for wettest month

	double userInput = 0;	// User input for rainfall per specified month
	double totalRain = 0;	// Total rain
	double averageRain = 0;	// Average rain
	double lowestRain = 0;	// Lowest rain
	double highestRain = 0;	// Highest rain

	cout << "Rainfall Database" << endl;
	cout << "This program will calculate the total, average, lowest, and highest rainfall for the past twelve months" << endl;
	cout << endl;

	for (int i = 0; i < 12; i++)
	{
		cout << "Please enter the amount of rainfall for the month of " << months[i] << ": ";
		cin >> userInput;
		while (userInput < 0)	// Input validation, rainfall cannot be negative
		{
			cout << "Rainfall cannot be negative." << endl;
			cout << "Please enter the amount of rainfall for the month of " << months[i] << ": ";
			cin >> userInput;
		}
		rainfall.storeValue(userInput); // Store user input values into array
	}

	totalRain = rainfall.total(); // Set totalRain equal to the rainfall total
	averageRain = rainfall.average();	// Set averageRain equal to the average rainfall over 12 months
	lowestRain = rainfall.lowest(lowMonth);	// Set lowest equal to lowest rainfall over 12 months and retrieve the month it occured
	highestRain = rainfall.highest(highMonth);	// Set highest equal to highest rainfall over 12 months and retreive the month it occured

	cout << endl;
	cout << "Rainfall Statistics for a 1-Year Period" << endl;
	cout << endl;
	cout << "Total Rainfall: " << totalRain << " inches." << endl;
	cout << "Average Rainfall: " << averageRain << " inches." << endl;
	cout << "Lowest Rainfall: " << lowestRain << " inches in month of " << months[lowMonth] <<  "." << endl;
	cout << "Highest Rainfall: " << highestRain << " inches in month of " << months[highMonth] << "." << endl;

	system("pause");
}