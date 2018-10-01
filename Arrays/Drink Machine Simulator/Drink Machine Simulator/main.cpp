#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "sodaMachine.hpp"

int main()
{
	sodaMachine soda;

	bool running = true; // Bool to keep while loop running. If user decides to exit running will be set to false
	double balance = 25; // Starting balance
	int selection = 0; // The drink the user chooses
	int repeat = 0; // Variable to make another purcahse

	cout << "Soda Dispenser" << endl;
	
	while (running != false) // While loop keeps going until user decides to exit which sets running to false
	{
		cout << endl;
		cout << "Balance on your card: $" << balance << endl;
		cout << endl;
		soda.displayChoices(); // Display drink choices
		cout << "Please enter your selection" << endl;
		cin >> selection;
		soda.buyDrink(selection, balance); // Sends user selection and user's balance to class function to purchase beverage

		cout << "Would you like to make another purchase?  " << endl; // Ask user if they want to repeat
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;

		cin >> repeat;
		if (repeat == 1) // Keep while loop running
		{
			running = true;
		}
		else // Exit while loop
			running = false;
	}

	soda.~sodaMachine(); // Call destructor which will call the display statistics function from the sodaMachine class

	cout << endl;
	cout << "...program terminated..." << endl;
	cout << endl;
	system("pause");
}