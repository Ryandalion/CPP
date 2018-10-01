#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printData(string name[], int jars[]);
void calcData(string name[], int jars[]);

int main()
{
	string salsaName [5] = {"Mild", "Medium", "Sweet", "Hot", "Zesty" };
	int jarsSold[5];

	cout << "Salsa Sales Database" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the number of " << salsaName[i] << " Jars sold: " << endl;
		cin >> jarsSold[i];
	}

	cout << endl;
	cout << "Sales Data" << endl;
	printData(salsaName, jarsSold);
	calcData(salsaName, jarsSold);

	system("pause");
	return 0;
}

void printData(string name[], int jars[])
{
	int j = 0;
	int n = 5;
	int sum = 0;
	int range[5];

	for (int i = 0; i < 5; i++)	//Display number of jars sold per category
	{
		cout << "Number of " << name[i] << " Jars sold: " << jars[j] << endl;
		j++;
	}

	for (int i = 0; i < 5; i++) //Display total number of jars sold
	{
		sum += jars[i];
	}

	cout << endl;
	cout << "The total sales are: " << sum << endl;
}

void calcData(string name[], int jars[])
{
	int small = jars[0];
	int big = jars[0];
	int high = 0;
	int low = 0;

	for (int i = 0; i < 5; i++)	// Find lowest value index
	{
		if (jars[i] < small)
		{
			small =jars[i];
			low = i;
		}
	}

	for (int j = 0; j < 5; j++)	// Find highest value index
	{
		if (jars[j] > big)
		{
			big = jars[j];
			high = j;
		}
	}

	cout << "Highest seller: " << name[high] << endl;
	cout << "Lowest seller: " << name[low] << endl;
}

