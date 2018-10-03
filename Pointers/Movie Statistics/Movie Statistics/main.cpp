#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

void sortData(double *students, int size);
double calcMedian(double *students, int size);
double calcMode(double *students, int size);
double calcMean(double *students, int size);

int main()
{

	double *movie;
	int numMovies = 0;
	int numStudents;

	double median = 0;
	int mode = 0;
	double mean = 0;

	cout << "How many students were surveyed?" << endl;
	cin >> numStudents;

	movie = new double[numStudents];

	for (int i = 0; i < numStudents; i++)
	{
		cout << "Please enter the number of movies student #" << i + 1 << " watched: ";
		cin >> movie[i];
		cout << endl;
	}

	sortData(movie, numStudents);
	for (int i = 0; i < numStudents; i++)
	{
		cout << movie[i] << endl;
	}

	median = calcMedian(movie, numStudents);
	mean = calcMean(movie, numStudents);
	mode = calcMode(movie, numStudents);

	cout << "The median is: " << median << endl;
	cout << "The mean is: " << mean << endl;
	cout << "The mode is: " << mode << endl;

	system("pause");
	return 0;
}

void sortData(double *students, int size)
{
	double temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size - 1; k++)
		{
			if (students[k] > students[k + 1])
			{
				temp = students[k + 1];
				students[k + 1] = students[k];
				students[k] = temp;
			}
		}
	}
}

double calcMedian(double *students, int size)
{
	int medianIndex = 0;
	double median = 0;

	if (size % 2 == 0)
	{
		medianIndex = (size / 2);
		median = ((students[medianIndex] + students[medianIndex - 1]) / 2);
	}

	else
	{
		medianIndex = (size / 2);
		median = students[medianIndex];
	}

	return median;
}

double calcMode(double *students, int size)
{
	int count = 0;
	int max = 0;
	int mode = 0;

	for (int i = 0; i < size; i++)
	{
		if (students[i] == students[i + 1])
		{
			count++;
			if (count > max)
			{
				max = count;
				mode = students[i];
			}
		}
		else
			count = 1;
	}

	return mode;
}

double calcMean(double *students, int size)
{
	double mean = 0;

	for (int i = 0; i < size; i++)
	{
		mean = mean + students[i];
	}

	mean = (mean / size);
	return mean;
}