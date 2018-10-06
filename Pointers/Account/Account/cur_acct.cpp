#include "cur_acct.hpp"

cur_acct::cur_acct()
{

}

double cur_acct::getCheckingsBalance() // Return Checkings balance
{
	balance = getBalance();
	return balance;
}

void cur_acct::deposit(double deposit) // Deposit the amount into account
{
	balance = balance + deposit;
}

double cur_acct::withdraw(double withdrawAmount) // Withdraw the amount from account
{
	if (balance > 0)
	{
		balance = balance - withdrawAmount;
		if (balance < 0)
		{
			cout << "Insufficient funds - Transaction Failed" << endl; // If user does not have enough money to withdraw display this message
		}
		else
			return withdrawAmount;
	}
	else
		cout << "Insufficient funds - Transaction Failed" << endl; // If balance is zero or negative then return the transaction failed message
}

bool cur_acct::transfer(double transfer) // Transfer from checkings account to savings account
{
	// Check that checkings account has enough money to be transferred
	if (balance >= transfer) // If balance is greater than transferAmount then transaction can occur
	{
		Account::setTransferAmount(transfer); // Push transferAmount to static transferAmount variable
		balance = balance - transfer; // Subtract the transferAmount from the Checkings account
		return true; // Return true that transaction is successful
	}
	else
		return false; // Return false if transaction is unsuccessful
}

void cur_acct::receiveTransfer() // Receive transfer amount
{
	balance = balance + transferAmount; // Receive the transferAmount and add it to balance
	transferAmount = 0; // Set the transfer amount to zero to clear for next transfer transaction
}

cur_acct::~cur_acct()
{

}