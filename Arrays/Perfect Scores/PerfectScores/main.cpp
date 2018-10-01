#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int countPerfect(int testScores[]);	

int main()
{
	int score;
	int testScores[10];

	cout << "Please enter 10 test scores. Values must be between 0 and 100." << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter score for test #" << i + 1 << ": " << endl;
		cin >> testScores[i];
		{
			while (testScores[i] < 0 || testScores[i] > 100)
			{
				cout << "Values must be between 0 and 100." << endl;
				cin >> testScores[i];
			}
		}
	}
	countPerfect(testScores);
	cout << countPerfect(testScores);
	system("pause");
}

int countPerfect(int testScores[])
{
	int perfect = 0;
	for (int i = 0; i < 20; i++)
	{
		if (testScores[i] == 100)
		{
			perfect++;
		}
	}
	return perfect;
}

