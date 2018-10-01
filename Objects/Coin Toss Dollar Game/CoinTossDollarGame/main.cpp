#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "coin.hpp"

bool checkBalance(int balance);

int main()
{
	srand(time(NULL));

	int balance = 0;
	bool running = true;
	int num = 0;

	Coin Quarter, Nickel, Dime;

	cout << "Coin Toss Dollar Game" << endl;
	cout << endl;
	cout << "Coin toss your way to a dollar. Flip your coins until you reach one dollar to win." << endl;
	cout << "If your balance exceeds one dollar you lose!" << endl;
	cout << "Good Luck!" << endl;
	cout << endl;
	cout << "Starting Balance: 0" << endl;
	cout << endl;
	while (running != false)
	{
		cout << "Round " << num + 1 << endl;
		cout << "Balance:  " << balance << " cents" << endl << endl;
		Quarter.toss();
		if (Quarter.getSideUp() == "Heads")
		{
			cout << "Quarter lands on Heads! 25 cents added to your balance" << endl << endl;
			balance = balance + 25;
			if (checkBalance(balance) == false)
			{
				running = false;
				break;
			}
		}
		
		else
		{
			cout << "Quarter lands on Tails! Nothing added to your balance" << endl << endl;
		}
			
		Dime.toss();
		if (Dime.getSideUp() == "Heads")
		{
			cout << "Dime lands on Heads! 10 cents added to your balance" << endl << endl;
			balance = balance + 10;
			if (checkBalance(balance) == false)
			{
				running = false;
				break;
			}
		}
		else
		{
			cout << "Dime lands on Tails! Nothing added to your balance" << endl << endl;
		}

		Nickel.toss();
		if (Nickel.getSideUp() == "Heads")
		{
			cout << "Nickel lands on Heads! 5 cents added to your balance" << endl << endl;
			balance = balance + 5;
			if (checkBalance(balance) == false)
			{
				running = false;
				break;
			}
		}
		else
		{
			cout << "Nickel lands on Tails! Nothing added to your balance" << endl << endl;
		}
		
		num++;
	}

	system("pause");
	return 0;
}

bool checkBalance(int balance)
{
	if (balance > 100)
	{
		cout << "You have exceeded one dollar. You lose. " << endl << endl;
		return false;
	}
	else if (balance == 100)
	{
		cout << "Congratulations, you have won!" << endl;
		return false;
	}
}