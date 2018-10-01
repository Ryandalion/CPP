#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double calcAverage(int monkey[][7], int& average);	// Calculate average amount of food the monkey family eats per day
int leastAmount(int monkey[][7], int& lowest); // Calculate the lowets amount of food eaten during the week
int greatAmount(int monkey[][7], int& highest); // Calculate the highest amount of food eaten during the week

int main()
{
	int monkeys[3][7] = {}; // 3 Monkeys and 7 meals a week
	int consumption;
	int average = 0;
	int lowest = 0;
	int highest = 0;

	cout << "Enter the amount of food eaten by each monkey over a 7 day period." << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Monkey #" << i + 1 << endl;
		for (int j = 0; j < 7; j++)
		{
			cout << "Please enter the amount of food eaten on day " << j + 1 << endl;
			cin >> consumption;
			monkeys[i][j] = consumption;
		}
		cout << endl;
	}

	calcAverage(monkeys, average);
	leastAmount(monkeys, lowest);
	greatAmount(monkeys, highest);

	cout << endl;
	cout << "MONKEY FOOD STATUS REPORT" << endl;
	cout << endl;
	cout << "The lowest amount of food eaten this week is " << lowest << " lbs of food per one day." << endl;
	cout << endl;
	cout << "The highest amount of food eaten this week is  " << highest <<" lbs of food per one day." << endl;
	cout << endl;
	cout << "The family of monkeys ate an average of " << average << " lbs of food per day over a 7 day period." << endl;
	system("pause");
}

double calcAverage(int monkey[][7],int& average) // Calculate average amount of food eaten by all monkeys in a one week period
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			average = average + monkey[i][j];
		}
	}
	average = (average / 7);

	return average;
}

int leastAmount(int monkey[][7], int& lowest)	// Calculate lowest amount of food eaten in one week
{
	lowest = monkey[0][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (monkey[i][j] < lowest)
			{
				lowest = monkey[i][j];
			}
		}
	}

	return lowest;
}

int greatAmount(int monkey[][7], int& highest)	// Calculate highest amount of food eaten in one week
{
	highest = monkey[0][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (monkey[i][j] > highest)
			{
				highest = monkey[i][j];
			}
		}
	}

	return highest;
}