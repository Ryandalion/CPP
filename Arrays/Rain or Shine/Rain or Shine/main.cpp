#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void readData(char weather[][30]);
int analyzeData(char weather[][30], int month, char weatherInput, int& frequency);
int analyzeAllData(char weather[][30], char mInput, char symbol[], int weatherMonth[]);
int analyzeThree(char weather[][30], char symbol[], int weatherMonth[]);

int main()
{
	// PROGRAM DATA
	char weather[3][30];								//Row = Months (0 = June, 1 = July, 2= August); Columns = Days (30 days)
	string months[3] = { "June", "July", "August" };
	char symbol[3] = { 'R','C','S' };
	string weathers[3] = { "Rainy", "Cloudy", "Sunny" };
	int weatherMonth[3];

	int frequency = 0;

	//DECISION INPUTS
	int database = 0;
	int input = 0;										// User choice for month to examine
	int mInput = 0;

	int weatherInput = 0;								// User choice for weather type to examine
	char wInput;

	int decision = 0;									// User choice to look at data for a different month
	int decision2 = 0;									// User choice to look for different weather type
	int decision3 = 0;									// User choice if they want to see all weather occurences for the given month

	bool running = true;								// Bool for main while loop (Months)
	bool running2 = true;								// Bool for inner while loop (Weather Type)

	readData(weather);									// Read weather data
	cout << "Weather Database" << endl;
	cout << "Please select an option from the menu below" << endl;
	cout << "1. Examine individual months" << endl;
	cout << "2. Examine all months combined" << endl;
	cout << "3. EXIT Program" << endl;
	cin >> database;
	while (database > 3 || database < 0)
	{
		cout << "Invalid Option" << endl;
		cout << "Please select from the following options" << endl;
		cin >> database;
	}
	if (database == 1)
	{
		while (running != false)
		{
			cout << "Please select the month you would like to examine: " << endl;
			cout << "1. June" << endl;
			cout << "2. July" << endl;
			cout << "3. August" << endl;
			cin >> input;
			cout << endl;

			while (input > 3 || input < 0)					// Validate input
			{
				cout << "Invalid input. Please try again." << endl;
				cout << "Enter the month you would like to examine: " << endl;
				cin >> input;
			}

			running2 = true;								// Reset bool
			cout << "You have chosen to examine the month of " << months[input - 1] << "." << endl;
			while (running2 != false)
			{
				cout << "Which weather type for the month of " << months[input - 1] << " would you like to examine? " << endl;
				cout << "1. Rainy" << endl;
				cout << "2. Cloudy" << endl;
				cout << "3. Sunny" << endl;

				cin >> weatherInput;
				while (weatherInput > 3 || weatherInput < 0)
				{
					cout << "Invalid input. Please try again." << endl;
					cout << "Enter the weather type you would like to examine: " << endl;
					cin >> weatherInput;
				}

				cout << endl;
				cout << "You have chosen to examine " << weathers[weatherInput - 1] << " days for the month of " << months[input - 1] << "." << endl;

				wInput = symbol[weatherInput - 1];
				mInput = (input - 1);

				analyzeData(weather, mInput, wInput, frequency);
				cout << "Here are the results" << endl;
				cout << weathers[weatherInput - 1] << ": " << frequency << endl;
				cout << endl;


				cout << "Would you like to see the weather details for the whole month? " << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;

				cin >> decision3;
				if (decision3 == 1)
				{
					frequency = 0;
					analyzeAllData(weather, mInput, symbol, weatherMonth);
					cout << "Rainy: " << weatherMonth[0] << endl;
					cout << "Cloudy: " << weatherMonth[1] << endl;
					cout << "Sunny: " << weatherMonth[2] << endl;

				}
				cout << endl;
				cout << "Would you like to search for another weather type for the month of " << months[input - 1] << "?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> decision2;
				if (decision2 == 2)
				{
					running2 = false;
				}
			}
			cout << endl;
			cout << "Would you like to examine another month" << endl;
			cout << "1. Yes" << endl;
			cout << "2. Exit Program" << endl;
			cin >> decision;
			if (decision == 2)
			{
				running = false;
			}

		}
	}

	else if (database == 2)
	{
	
		analyzeThree(weather, symbol, weatherMonth);
		cout << "Total Weather Data" << endl;
		cout << "For the months of June, July, August" << endl;
		cout << "Rainy: " << weatherMonth[0] << endl;
		cout << "Cloudy: " << weatherMonth[1] << endl;
		cout << "Sunny: " << weatherMonth[2] << endl;

	}

	cout << endl;
	cout << "Good bye" << endl;
	cout << endl;
	system("pause");
}

void readData(char weather[][30])
{
	ifstream inFile;
	const int SIZE = 30;								// Read 30 characters because only 30 days
	char RCS[SIZE];
	
	inFile.open("RainOrShine.dat");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			inFile >> weather[i][j];
		}
	}
}

int analyzeData(char weather[][30], int mInput, char wInput, int& frequency)	//Check how many instances of user chosen weather occurs in user chosen month
{
	for(int i = 0; i < 30; i++)
	{
		if (weather[mInput][i] == wInput)
		{
			frequency++;
		}
	}
	return frequency;
}

int analyzeAllData(char weather[][30],char mInput, char symbol[], int weatherMonth[]) //Calculate how many occurences of each weather type occurs for the given month
{
	int rainy = 0;
	int cloudy = 0;
	int sunny = 0;

	for (int i = 0; i < 30; i++)
	{
		if (weather[mInput][i] == symbol[0])
		{
			rainy++;
		}

		if (weather[mInput][i] == symbol[1])
		{
			cloudy++;
		}

		if (weather[mInput][i] == symbol[2])
		{
			sunny++;
		}
	}

	weatherMonth[0] = rainy;
	weatherMonth[1] = cloudy;
	weatherMonth[2] = sunny;

	return weatherMonth[3];
}

int analyzeThree(char weather[][30], char symbol[], int weatherMonth[])
{
	int rainy = 0;
	int cloudy = 0;
	int sunny = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (weather[i][j] == symbol[0])
			{
				rainy++;
			}
			if (weather[i][j] == symbol[1])
			{
				cloudy++;
			}
			if (weather[i][j] == symbol[2])
			{
				sunny++;
			}
		}
	}

	weatherMonth[0] = rainy;
	weatherMonth[1] = cloudy;
	weatherMonth[2] = sunny;

	return weatherMonth[3];
}