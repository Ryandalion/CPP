#include <iostream>
#include <time.h>
#include <iomanip>


#include "fish.hpp"

using std::setw;
using std::cout;
using std::cin;
using std::endl;

using std::left;
using std::right;



int main()
{
	srand(time(NULL));

	const int indent = 10;
	int choice = 0;
	bool running = true;
	int total = 0;
	
	Fish p1;

	cout << "Welcome to Fishing Simulator" << endl;
	cout << endl;
	cout << "You will be given a rod and some bait to catch some fish!" << endl;
	cout << "Your objective is to accumulate as many fish as possible." << endl;
	cout << "Each fish/item is worth a certain number of points." << endl;
	cout << "Here is a list of items and their points: " << endl;
	cout << endl;
	cout << left << setw(25) << "ITEMS" << right << setw(indent) << "POINTS" << "\n";
	cout << endl;
	cout << left << setw(25) << "BASS" << right << setw(indent) << "6" << "\n";
	cout << left << setw(25) << "CATFISH" << right << setw(indent) << "4" << "\n";
	cout << left << setw(25) << "OLD TIRE" << right << setw(indent) << "-1" << "\n";
	cout << left << setw(25) << "GOLDFISH" << right << setw(indent) << "4" << "\n";
	cout << left << setw(25) << "OCTOPUS" << right << setw(indent) << "3" << "\n";
	cout << left << setw(25) << "FISHING NET" << right << setw(indent) << "0" << "\n";
	cout << endl;
	cout << "Time to go fishing!" << endl;

	while (running != false)
	{
		cout << endl;
		cout << "You cast your rod into the stream" << endl;
		cout << "You feel a bite!" << endl;
		p1.rolldice();
		p1.setStats();
		cout << "You caught a " << p1.objectname() << "!" << endl;
		total += p1.totalPoints();
		cout << endl;
		cout << "Would you like to continue fishing? " << endl;
		cout << "1. Yes, let's keep fishing! " << endl;
		cout << "2. No, let's go home" << endl;
		cin >> choice;

		if (choice == 1)
		{
			running = true;
		}
		else
		{
			running = false;
		}
		
	}
	
	cout << endl;
	cout << "You have decided to go home." << endl;
	cout << "Congratulations, you got " << total << " points!" << endl;
	cout << "Goodbye" << endl;

	system("pause");
}

