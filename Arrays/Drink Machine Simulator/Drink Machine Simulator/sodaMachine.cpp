#include "sodaMachine.hpp"

sodaMachine::sodaMachine()
{
	
}

void sodaMachine::displayChoices()
{
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << "Drink Name: " << soda[i].sodaName << endl; // Print soda name
		cout << "   Price: $" << soda[i].sodaCost << endl; // Print soda price
		cout << endl;
	}
}

void sodaMachine::buyDrink(int selection, double& balance)
{
	selection = selection - 1; // Subtract one from the user's selection so the index starts at the correct place
	inputMoney(selection, balance); // Call input money function and send the user's selection and their balance
}

void sodaMachine::inputMoney(int selection, double& balance)
{
	int confirm = 0; // User decision to proceed with purchase or exit
	double cost = 0; // Cost is equal to soda cost and is used to calculate the total sales

	cout << endl;
	cout << "You have chosen " << soda[selection].sodaName << endl;
	cout << "Please confirm to proceed" << endl;
	cout << "1. Confirm" << endl;
	cout << "2. Exit" << endl;
	cin >> confirm;
	if (confirm == 1) // Continue with purchase
	{
		if (balance >= soda[selection].sodaCost) // Check if user has enough money in account
		{
			if (soda[selection].sodaQuantity >= 1) // Check if there is any soda avaiable to be sold
			{
				cost = soda[selection].sodaCost; // Cost => Soda cost
				sales = sales + cost; // Sales = Accumulated costs
				balance = balance - cost; // Change the balance via subtracting soda cost. Since we are passing by reference balance will be changed in main also
				soda[selection].sodaQuantity -= 1; // Decrease the quantity of soda respective to the type of soda
				cout << endl;
				cout << "Your beverage has been delivered" << endl; // Display confirmation message to customer
				cout << endl;
			}
			else // If there is no soda left to be sold, print a message that states that product is sold out and money has been refunded back to user's account
			{
				cout << "Product is sold out" << endl;
				cout << "Money has been refunded to your account" << endl;
			}
		}

		else // If there is not enough money in the user's account, print message that states they do not have enough money for the purchase
		{
			cout << "Balance is too low" << endl;
		}
	}
	else if (confirm == 2) // If they do not wish to proceed with purcahse, print message that states that money has been refunded to account
	{
		cout << "Money has been refunded to your account" << endl;
		cout << endl;
	}
	
}

void sodaMachine::dailyReport() // Print total sales and quantity left per each type of soda
{
	cout << endl;
	cout << "Soda Machine Report" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Soda Name: " << soda[i].sodaName << endl;
		cout << "Quantity Left: " << soda[i].sodaQuantity << endl;
		cout << endl;
	}

	cout << "Total sales: $" << sales << endl;
}

sodaMachine::~sodaMachine()
{
	dailyReport(); // Execute the daily report function to display all sales information to owner of machine
}
