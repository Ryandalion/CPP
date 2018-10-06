#include "Account.hpp"
#pragma once

class cur_acct : 
	public Account
{
public:

	cur_acct();
	
	double getCheckingsBalance(); // Check balance
	void deposit(double amount); // Deposit money into balance
	double withdraw(double withdrawAmount); // Withdraw money
	bool transfer(double transfer); // Transfer to Savings Account
	void receiveTransfer(); // Checking Account is triggered to recieve transfer from Savings account

	~cur_acct();

private:
	
	double minBalance = 100; // Minimum balance required in account
	double serviceCharge = 20.50; // Service charge if 
};