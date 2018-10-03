#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int calcMode(int *piePointer);

int main()
{
	// Create a dynamically allcoated array
	int *pieArray;
	
	pieArray = new int[5];
	
	// Create a pointer that can point to pieArray
	int *piePointer;
	piePointer = pieArray;

	cout << "Please enter the number of pies you ate this year" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the number of pies you ate this year: ";
		cin >> pieArray[i];
	}
	int mode = 0;
	mode = calcMode(piePointer);
	cout << mode << endl;
	delete[] pieArray;

	system("pause");
	return 0;
}

int calcMode(int *piePointer)
{
	// Find mean
	int mode = 0;
	int counter = 0;
	int max = 0;

	for (int i = 0; i < 5; i++)
	{
		if (piePointer[i] == piePointer[i + 1])
		{
			counter++;
			if( counter > max)
			{
				max = counter;
				mode = piePointer[i];
			}
		}
		else
		{
			counter = 1;
		}

	}
	return mode;
}