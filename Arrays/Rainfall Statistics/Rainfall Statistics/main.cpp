#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void getData(double rainData[], string months[]);				// Gather rainfall data per month from user
double totalRainfall(double rainData[]);						// Calculate total rainfall using rainData array
double averageRainfall(double totalRain);						// Calculate average rainfall by taking total rainfall / 12
double driestMonth(double rainData[], int& lowIndex);			// Calculate lowest month of rainfall
double wettestMonth(double rainData[], int& highIndex);			// Calculate highest month of rainfall

int main()
{
	double rainData[12];										// rainData array 12 spots for 12 months
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }; // Months to display to user

	double totalRain = 0;										
	double averageRain = 0;											
	int lowIndex = 0;
	int highIndex = 0;
	double lowestRain = 0;
	double highestRain = 0;

	cout << "Annual Rainfall Database" << endl;
	cout << "This program will calculate the total rainfall, average rainfall, lowest rainfall, and highest rainfall." << endl;
	cout << endl;

	getData(rainData, months);
	totalRain = totalRainfall(rainData);
	averageRain = averageRainfall(totalRain);
	lowestRain = driestMonth(rainData, lowIndex);
	highestRain = wettestMonth(rainData, highIndex);

	cout << endl;
	cout << "Rainfall Report for Region" << endl;
	cout << "Total rainfall: " << totalRain << " inches." << endl;
	cout << "Average monthly rainfall: " << averageRain << " inches." << endl;
	cout << "The least rain fell in " << months[lowIndex] << " with " << lowestRain << " inches." << endl;
	cout << "The most rain fell in " << months[highIndex] << " with " << highestRain << " inches." << endl;

	system("pause");

	return 0;
}

void getData(double rainData[], string months[])
{
	double rainfall = 0;

	for (int i = 0; i < 12; i++)
	{
		cout << "Enter the total rainfall for the month of " << months[i] << ": " << endl;
		cin >> rainfall;
		while (rainfall < 0)
		{
			cout << "Rainfall cannot be negative. Please enter a valid number: " << endl;
			cin >> rainfall;
		}
		rainData[i] = rainfall;
		cin.clear();
	}
}

double totalRainfall(double rainData[])
{
	double total = 0;

	for (int i = 0; i < 12; i++)
	{
		total = total + rainData[i];
	}

	return total;
}

double averageRainfall(double totalRain)
{
	double average = 0; 

	average = (totalRain / 12);
	
	return average;
}

double driestMonth(double rainData[], int& lowIndex)
{
	double low = rainData[0];
	
	for (int i = 0; i < 12; i++)
	{
		if (rainData[i] < low)
		{
			low = rainData[i];
			lowIndex = i;
		}
	}

	return low;
}

double wettestMonth(double rainData[], int& highIndex)
{
	double high = rainData[0];

	for (int i = 0; i < 12; i++)
	{
		if (rainData[i] > high)
		{
			high = rainData[i];
			highIndex = i;
		}
	}

	return high;
}