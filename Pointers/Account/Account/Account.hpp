#include <iostream>
#include <string>
#include <ctime>

#pragma once

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account
{
public:

	Account();

	void setAccountType(int accountType); // Set account type
	void setName(string name); // Set user name
	void setAccountNum(); // Set account number
	void setBalance(double deposit); // Set account balance
	void setTransferAmount(double transfer); // Set transfer amount
	double getBalance(); // Return balance of user
	string getName(); // Get user name

	string name;
	int accountNumber;
	string accountType; 
	double balance;

	static double transferAmount; // Static transferAmount that will hold the transferAmount sent by Savings account or Checkings account

	~Account();

private:

};

