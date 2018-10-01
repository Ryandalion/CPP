#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

void getData(vector<string>& teams);								// Gather Team data from team.txt file and store in vector
void printData(const vector<string>& teams);						// Print all times from the Team vector
void sortData(vector<string>& wins);								// Gather World Series Winners data from WorldSeriesWinners.txt file and store in vector
int findWins(const vector<string>& wins, string teamName);			// Find the number of wins the user selected team has

int main()
{
	vector<string> team;											// Vector for team names
	vector<string> wins;											// Vector for wins
	string teamName = " ";											// User input team name
	int numWins = 0;												// Number of wins user input team has

	getData(team);													// Call function to gather team data
	sortData(wins);													// Call function to gather winning team data
	cout << "Welcome to the Baseball World Series Champions Database" << endl;
	cout << "Here is a list of all MLB teams" << endl;
	cout << endl;
	printData(team);												// Print all team names

	cout << "Enter the team you want to examine for their number of World Series Titles" << endl;
	std::getline(cin, teamName);									// Get team name that user wishes to find


	cout << endl;
	numWins = findWins(wins, teamName);								// Set number of wins equal to what findWins returns
	cout << endl;
	cout << "The " << teamName << " have won " << numWins << " times!" << endl;
	system("pause");
}

void getData(vector<string>& teams)									// Gather data from .txt file
{
	ifstream readFile;
	readFile.open("Teams.txt");
	string  teamNames;
	while (!readFile.eof())
	{
		while (std::getline(readFile, teamNames))					// Read until end of line
		{
			teams.push_back(teamNames);
		}
	}
	readFile.close();
}

void printData(const vector<string>& teams)							// Print the data for vectors
{
	for (unsigned int i = 0; i < teams.size(); i++)
	{
		cout << teams[i] << endl;
	}
}

void sortData(vector<string>& wins)									// Gather data from .txt file ==> WorldSeriesWinners.txt
{
	ifstream openFile;
	openFile.open("WorldSeriesWinners.txt");
	string input;

	while (!openFile.eof() && std::getline(openFile, input))
	{
		wins.push_back(input);
	}

	openFile.close();
}

int findWins(const vector<string>& wins, string teamName)			// Find number of wins for user input team
{
	int index = 0;
	for (unsigned int i = 0; i < wins.size(); i++)
	{
		if (wins[i] == teamName)
		{
			index++;
		}
	}

	return index;
}