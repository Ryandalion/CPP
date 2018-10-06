#include "Account.hpp"

double Account::transferAmount; // Static variable

Account::Account()
{
	name = " ";
	accountNumber = 0;
	accountType = " ";
	balance = 0;
}

void Account::setName(string name) // Set user name
{
	this->name = name;
}

void Account::setAccountType(int accountType) // Set account type
{
	string checkingAccount = "Checking Account";
	string savingsAccount = "Savings Account";

	if (accountType == 1)
	{
		this->accountType = checkingAccount;
	}
	
	else if (accountType == 2)
	{
		this->accountType = savingsAccount;
	}
}

void Account::setAccountNum() // Generate account number via random number generation
{
	int accountNum[5];

	for (int i = 0; i < 5; i++)
	{
		accountNum[i] = rand() % 10;
	}
}

double Account::getBalance() // Get account balance
{
	return balance;
}

void Account::setBalance(double deposit) // Add deposit to balance
{
	balance = deposit;
}

void Account::setTransferAmount(double transfer) // Set transfer Amount
{
	transferAmount = transfer; // Move transfer amount to static variable transferAmount
}

string Account::getName() // Return name
{
	return name;
}

Account::~Account()
{

}

