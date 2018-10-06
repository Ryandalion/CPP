#include "sav_acct.hpp"

sav_acct::sav_acct()
{
	interestRate = 3.3;
}

void sav_acct::deposit(double amount) // @param AMOUNT ==> money that will be deposited into savings account
{
	balance = balance + amount; // Savings Balance is updated with the deposited amount
}

double sav_acct::getSavingsBalance() // Get account balance for savings account
{
	return balance;
}

double sav_acct::withdraw(double withdrawAmount)
{
	if (balance > 0)
	{
		balance = balance - withdrawAmount;
		if (balance < 0)
		{
			cout << "Insufficient funds" << endl;
		}
		else
			return withdrawAmount;
	}
	else
		cout << "Insufficient funds" << endl;
}

bool sav_acct::transfer(double transfer) // Transfer money from savings to checkings account
{
	if (balance >= transfer) // If balance is greater than transferAmount then transaction can occur
	{
		Account::setTransferAmount(transfer);
		balance = balance - transfer;
		return true;
	}
	else
		return false;
}

double sav_acct::computeInterest(int month)
{
	double interestBalance;

	if (month == 1) // In one month account accrues interestAPR times 1
	{
		interestBalance = balance * (1 + (interestRate/100) * 1/12);
	}

	else if (month == 6) // In 6 months account accrues interestAPR times 6
	{
		interestBalance = balance * (1 + (interestRate / 100) * 6 / 12);
	}

	else if (month == 12) // In 12 months account accrues interestAPR times 12
	{
		interestBalance = balance * (1 + (interestRate/100) * 12/12);
	}
	
	return interestBalance;
}

void sav_acct::receiveTransfer()
{
	balance = balance + transferAmount;
	transferAmount = 0; // Clear the transfer amount
}

sav_acct::~sav_acct()
{

}