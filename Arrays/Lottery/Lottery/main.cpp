#include <iostream>
#include <time.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;

void generateLucky(int winningDigits[]);											// Generate the lucky numbers using simple rand() function and store them in winningDigits array
int compareNumbers(int winningDigits[], int player[]);								// Compare the player's numbers and lucky numbers and determine number of matching elements 
int generateLuckyList(int winningDigits[], int player[], int luckyNumbers[]);		// Compare the player's numbers and lucky numbers and store matching numbers in luckyNumbers array

int main()
{
	srand(time(NULL));							// Initialize random seed
	int playerNum = 0;							// Player chosen digits
	int numElements = 0;						// Number of matching elements to dynamically allocate array
	int winningDigits[5];						// Array to hold winning digits
	int player[5];								// Array to hold player's chosen digits
	bool running = true;						// Play again option
	int decision = 0;							// Decision to play again
	int numWon = 0;								// Number of lucky numbers


	while (running != false)					// If false while loop terminates and program exits
	{
		generateLucky(winningDigits);			// Generate lucky numbers. Generate now so not perceived as "rigged"

		cout << "Welcome to the Lottery simulator" << endl;
		cout << "Let's see if you can win the lottery!" << endl;
		cout << endl;
		cout << "Enter 5 digits that you think are lucky! Values must be between 0-9" << endl;
		cin >> playerNum;
		while (playerNum > 9 || playerNum < 0)							// Validate input
		{
			cout << "Value must be between 0 and 9" << endl;
			cout << "Please enter 5 digits. Values must be between 0-9" << endl;
			cin >> playerNum;
		}

		player[0] = playerNum;											// Initialize player[0] to player entered digit

																		// Get player digits; Start at i = 1 because we already have a value for player[0]
		for (int i = 1; i < 5; i++)
		{
			cout << "Please enter the next value: " << endl;
			cin >> playerNum;
			while (playerNum > 9 || playerNum < 0)						// Validate input
			{
				cout << "Value must be between 0 and 9" << endl;
				cout << "Please enter 5 digits. Values must be between 0-9" << endl;
				cin >> playerNum;
			}
			player[i] = playerNum;
		}
		cout << endl;

		numElements = compareNumbers(winningDigits, player);			 // Call function to compare number of elements and return the number of matching elements and store in numElements
																		// numElements will be used to dynamically allocate space for the array to hold winning numbers
		int* luckyNumbers = NULL;
		luckyNumbers = new int[numElements];							 // Dynamically allocate array for number of matching elements

		numWon = generateLuckyList(winningDigits, player, luckyNumbers); // Collect the numbers that match
		
		if (numElements == 0)											// If there are no matches then numElements = 0 and user did not win
		{
			cout << "You did not win" << endl;
			cout << setw(20) << "Here are your numbers:      ";
			for (int i = 0; i < 5; i++)
			{
				cout << player[i] << " ";
			}
			cout << endl;
			cout << setw(10) << "Here are the lucky numbers: ";
			for (int i = 0; i < 5; i++)
			{
				cout << winningDigits[i] << " ";
			}
		}

		else if (numElements != 0)											// If numElements is greater than zero than that means there is a match and the user won
		{
			cout << "Congratulations! It must be your lucky day!" << endl;
			cout << endl;
			if (numWon == 1)												// Syntax if only one winning number
			{
				cout << "You matched a total of " << numWon << " number!" << endl;
			}

			else if (numWon > 1)											// Syntax if more than one winning number
			{
				cout << "You matched a total of " << numWon << " numbers!" << endl;
			}
			cout << "Here are the numbers you matched: ";

			for (int i = 0; i < numElements; i++)							// Print number that is found between the two arrays
			{
				cout << luckyNumbers[i] << endl;
			}


			cout << setw(20) << "Here are your numbers:      ";				// Print player's numbers
			for (int i = 0; i < 5; i++)
			{
				cout << player[i] << " ";
			}

			cout << endl;

			cout << setw(10) <<  "Here are the lucky numbers: ";			// Print winning numbers
			for (int i = 0; i < 5; i++)
			{
				cout << winningDigits[i] << " ";
			}

		}

		delete[] luckyNumbers;									// Deallocate array
		
		cout << endl;
		cout << endl;
		cout << "Would you like to play again? " << endl;		// Ask user if they wish to play again
		cout << "1. Yes, lady luck is on my side" << endl;
		cout << "2. No" << endl;
		cin >> decision;
		while (decision > 2 || decision < 0)					// Validate input
		{
			cout << "Invalid option" << endl;
			cout << "Please try again" << endl;
			cin >> decision;
		}

		if (decision == 2)										// If user decides to quit playing then set bool to false which will terminate out of while loop
		{														// If user decides to continue playing jump back to top
			running = false;
		}
	}
	system("pause");
}

void generateLucky(int winningDigits[])							// Generate random numbers using standard rand function
{
	for (int i = 0; i < 5; i++)
	{
		int x = rand() % 10;
		winningDigits[i] = x;
	}
}

int compareNumbers(int winningDigits[], int player[])			// Compare the player's numbers and winning numbers. If the element at the index match store them in luckyNumbers array
{
	int j = 0;													// j is the number of matching elements between the winningDigits array and player array

	for (int i = 0; i < 5; i++)
	{
		if (winningDigits[i] == player[i])
		{
			j++;
		}
	}

	return j;
}

int generateLuckyList(int winningDigits[], int player[], int luckyNumbers[])		// After allocating space for the lucky number list we can fill it in with the winning numbers
{
	int index = 0;

	for (int i = 0; i < 5; i++)
	{
		if (winningDigits[i] == player[i])
		{
			luckyNumbers[index] = winningDigits[i];									// Store matching values in luckyNumbers array
			index++;	
		}
	}

	return index;																	// Return the index value 
}