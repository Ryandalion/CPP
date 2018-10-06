#include "Account.hpp"
#pragma once

class sav_acct : 
	public Account
{
public:

	sav_acct();

	void deposit(double amount); // Deposit money into savings account
	double getSavingsBalance(); // Get balance for savings account
	double withdraw(double withdrawAmount); // Withdraw from savings account
	bool transfer(double transferAmount); // Transfer to Checkings account
	void receiveTransfer(); // Send the transfer to Checkings account
	double computeInterest(int month); // Compute interest rate using => Balance * (1 + (interest rate/100) * duration)

	~sav_acct();

private:

	double interestRate = 3.3;


};