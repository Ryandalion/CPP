#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void sortArray(double *pointer, int size);
double findMedian(double *pointer, int size);

int main()
{
	int size = 0;
	double *Array;
	
	cout << "Please enter how many digits you will input into this function: ";
	cin >> size;

	Array = new double[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Please enter the value: " << endl;
		cin >> Array[i];
		cout << endl;
	}

	double median = 0;

	sortArray(Array, size);
	
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << endl;
	}

	median = findMedian(Array, size);

	cout << "The median is " << median << endl;


	system("pause");
	return 0;
}

void sortArray(double *pointer, int size)
{
	int hold;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (pointer[j] > pointer[j + 1])
			{
				hold = pointer[j + 1];
				pointer[j + 1] = pointer[j];
				pointer[j] = hold;
			}
		}
	}
}

double findMedian(double *pointer, int size)
{
	double median = 0;
	int medianIndex = 0;

	if (size % 2 == 0)
	{
		medianIndex = (size / 2);
		median = (pointer[medianIndex] + pointer[medianIndex - 1])/2;
	}

	else
	{
		medianIndex = (size / 2);
		median = pointer[medianIndex];
	}

	return median;
}