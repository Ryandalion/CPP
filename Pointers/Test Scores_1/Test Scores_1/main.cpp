#include <iostream>
#include <string>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::swap;

void sortData(double* testScores, int num);
double calcAverage(double* testScores, int num);

int main()
{
	int numTests = 0;
	double grade = 0;
	double *testScores;
	double average = 0;
	

	cout << "Test Score Calculator" << endl;
	cout << "Please enter the number of tests you will be inputting today: ";
	cin >> numTests;
	cout << endl;

	testScores = new double[numTests];

	for (int i = 0; i < numTests; i++)
	{
		cout << "Please enter the score for student #" << i + 1 << ": ";
		cin >> grade;
		testScores[i] = grade;
		cout << endl;
	}

	sortData(testScores, numTests);
	average = calcAverage(testScores, numTests);

	cout << "Grades in ascending order" << endl;
	for (int i = 0; i < numTests; i++)
	{
		cout << testScores[i] << endl;

	}

	cout << "Average is: " << average << endl;

	delete[] testScores;

	system("pause");

	return 0;
}

void sortData(double *testScores, int num) // Bubble Sort
{
	double swap;

	for (int i = 0; i < (num - 1); i++)
	{
		for (int k = 0; k < num - i - 1; k++)
		{
			if (testScores[k] > testScores[k + 1]) 
			{
				swap = testScores[k];
				testScores[k] = testScores[k + 1];
				testScores[k + 1] = swap;
			}
		}
	}
}

double calcAverage(double *testScores, int num)
{
	double average = 0;

	for (int i = 0; i < num; i++)
	{
		average = average + testScores[i];
	}

	return average = (average / num);
}