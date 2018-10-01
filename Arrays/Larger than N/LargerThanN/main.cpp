#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void displayArray(int[], int size, int n);

int main()
{
	int n = 0;
	int listnum[10];
	int size = 10;
	int num = 0;

	cout << "This program will count how many numbers are larger than N." << endl;
	cout << "N can be any number of your choice." << endl;
	cout << "Please assign a number for N: " << endl;
	cin >> n;
	cout << "Please enter 10 numbers" << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cin.ignore();
		cout << "Please enter number " << i + 1 << " :" << endl;
		cin >> listnum[i];
		cin.clear();
	}

	displayArray(listnum, size, n);

	system("pause");
	return 0;
}

void displayArray(int listnum[], int size, int n)
{
	int newArray[10];
	int count = 0;
	int j = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (listnum[i] > n)
		{
			newArray[j] = listnum[i];
			count++;
			j++;
		}

	}

	cout << endl;
	cout << "Here are the values that are greater than " << n << endl;
	for (int i = 0; i < count; i++)
	{
		cout << newArray[i] << endl;
	}
}