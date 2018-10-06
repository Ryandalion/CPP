//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// PROGRAM NAME: BANK ACCOUNT SYSTEM W/ VIRTUAL ATM SYSTEM																																		
// FUNCTIONS
// 1) Account creation => Create new user ID and password. Initial balance for Checking account and Savings account is set.																					
// 2) User ID verification => A) Checks if username is in system. B) When user logs in, the program checks the username and password that is stored in a dat file to verify user credentials
// 3) Balance Lifetime => Checking Balance and Saving Balance per each user persists even if program is terminated. This is achieved via data stored in .dat files
// 4) Transactions => User has the ability to  deposit, withdraw, transfer between accounts, and check the balance of each account (Checkings/Savings)
// 5) Interest Rate => Calculates 1 Month, 6 Month, 12 Month projected Interest Rate gains using Bank's propietary APR interest rate
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <sstream>

#include "cur_acct.hpp"
#include "sav_acct.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::stringstream;


bool verifyLogin(string &userName,cur_acct &checking,sav_acct &savings, vector<string>& userCheckings, vector<string>& userSavings); // Multi-step function to either a) verify user or b) create user login and intialize account
bool verifyuserName(string checkName);

int main()
{
	cur_acct checking; // Object to hold Checking account information
	sav_acct savings;  // Object to hold Savings account information

	string userName; // User input name

	vector<string> userCheckings; // Vector to hold user's Checking account balance
	vector<string> userSavings;   // Vector to hold user's Savings account balance

	if (verifyLogin(userName, checking, savings, userCheckings, userSavings))
	{
		bool running = true; // Main Loop
		bool running2 = true; // Inner Loop 

		int accountDecision = 0;

		checking.setName(userName); // Set account name for checking account
		savings.setName(userName); // Set accoutn name for savings account


		cout << "ATM - Bank of C++" << endl;
		cout << endl;
		cout << "Welcome back " << userName << "!" << endl;
		cout << endl;
		while (running != false)
		{
			cout << endl;
			cout << "Please select an option" << endl;
			cout << "1. Checkings Account" << endl;
			cout << "2. Savings Account" << endl;
			cout << "3. Exit" << endl;
			cin >> accountDecision;

			if (accountDecision == 1) // Checkings Account
			{
				running2 = true;
				while (running2 != false)
				{

					int checkingDecision = 0;
					cout << endl;
					cout << userName << "'s Checking Account" << endl;
					cout << endl;
					cout << "Please select an option" << endl;
					cout << "1. Deposit" << endl;
					cout << "2. Withdraw" << endl;
					cout << "3. Check Balance" << endl;
					cout << "4. Transfer to Savings Account" << endl;
					cout << "5. Exit" << endl;

					cin >> checkingDecision;

					if (checkingDecision == 1) // Deposit money into the checking account function
					{
						double depositAmount = 0; // Amount that will be deposited

						cout << endl;
						cout << "Please enter the amount you would like deposit" << endl;
						cin >> depositAmount;

						while (depositAmount < 0) // Check to make sure deposit amount is not negative
						{
							cout << endl;
							cout << "Amount cannot be negative. Please enter a valid amount." << endl;
							cin >> depositAmount;
						}

						checking.deposit(depositAmount);

					}

					else if (checkingDecision == 2) // Withdraw money from checking account function
					{
						double withdrawAmount = 0; // Amount that user will withdraw
						int decision = 0; // User decision

						cout << "Please select an amount to withdraw" << endl;
						cout << "1. $25" << endl;
						cout << "2. $50" << endl;
						cout << "3. $100" << endl;
						cout << "4. $200" << endl;
						cout << "5. $300" << endl;
						cout << "6. $5000" << endl;

						cin >> decision;
						if (decision == 1)
						{
							withdrawAmount = 25;
						}

						else if (decision == 2)
						{
							withdrawAmount = 50;
						}

						else if (decision == 3)
						{
							withdrawAmount = 100;
						}

						else if (decision == 4)
						{
							withdrawAmount = 200;
						}

						else if (decision == 5)
						{
							withdrawAmount = 300;
						}

						else if (decision == 6)
						{
							withdrawAmount = 5000;
						}


						withdrawAmount = checking.withdraw(withdrawAmount); // Withdraw user requested amount from Checking account

						if (withdrawAmount > 1) // Withdraw is successful, print message of successful transaction
						{
							cout << "Withdrawal Successful" << endl;
							cout << "$" << withdrawAmount << " withdrawn" << endl;
						}
					}

					else if (checkingDecision == 3) // Function to check Checking account balance
					{
						double balance = 0;
						balance = checking.getCheckingsBalance(); // Retrieve Checking account balance
						cout << endl;
						cout << "Checking Account Balance: ";
						cout << "$" << balance << endl;
					}

					else if (checkingDecision == 4) // Function to transfer money from Checkings to Savings
					{

						double transfer = 0; // Initialize transfer to zero

						cout << "Transfer money from Checkings Account to Savings Account" << endl;
						cout << "Please enter the amount you would like to transfer to Savings" << endl;
						cin >> transfer;

						while (transfer <= 0) // If transfer amount is below zero print message below
						{
							cout << endl;
							cout << "Transfer amount cannot be negative. Please enter a valid amount." << endl;
							cin >> transfer;
						}

						if (checking.transfer(transfer)) // Transfer money from Checkings to Savings function
						{
							savings.receiveTransfer(); // Trigger Savings account to accept transfer
							cout << endl;
							cout << "Transaction Successful - $" << transfer << " transferred to Savings" << endl;
						}
						else // User does not have enough money to complete transfer from Checkings to Savings
						{
							cout << "Insufficient Funds- Transaction Failed" << endl;
						}
					}

					else if (checkingDecision == 5) // Exit from Checking account
						running2 = false;
				}

			}

			else if (accountDecision == 2) // Savings Account
			{
				running2 = true;
				while (running2 != false)
				{
					int savingsDecision = 0;
					cout << userName << "'s Savings Account" << endl;
					cout << endl;
					cout << "Please select an option" << endl;
					cout << "1. Deposit" << endl;
					cout << "2. Withdraw" << endl;
					cout << "3. Check Balance" << endl;
					cout << "4. Transfer to Checkings" << endl;
					cout << "5. Exit" << endl;

					cin >> savingsDecision;

					if (savingsDecision == 1) // Deposit into Savings account
					{
						double depositAmount = 0; // Amount user wishes to deposit
						cout << "Please enter the amount you would like to deposit" << endl;
						cin >> depositAmount;
						while (depositAmount < 0) // If deposit amount is less than zero
						{
							cout << "Amount cannot be negative. Please enter a valid amount." << endl;
							cin >> depositAmount;
						}

						savings.deposit(depositAmount); // Deposit the requested amount into savings

					}

					else if (savingsDecision == 2) // Withdraw from Savings account
					{
						double withdrawAmount = 0; // Intialize withdraw amount to zero
						int decision = 0; // Intialize decision to zero

						cout << "Please select an amount to withdraw" << endl;
						cout << "1. $25" << endl;
						cout << "2. $50" << endl;
						cout << "3. $100" << endl;
						cout << "4. $200" << endl;
						cout << "5. $300" << endl;
						cout << "6. $5000" << endl;

						cin >> decision;
						if (decision == 1)
						{
							withdrawAmount = 25;
						}

						else if (decision == 2)
						{
							withdrawAmount = 50;
						}

						else if (decision == 3)
						{
							withdrawAmount = 100;
						}

						else if (decision == 4)
						{
							withdrawAmount = 200;
						}

						else if (decision == 5)
						{
							withdrawAmount = 300;
						}

						else if (decision == 6)
						{
							withdrawAmount = 5000;
						}


						savings.withdraw(withdrawAmount); // Withdraw from the Savings account the amount that was chosen by the user

						if (withdrawAmount > 1) // Check to make sure withdraw amount is greater than $1
						{
							cout << "Withdrawal Successful" << endl;
							cout << "$" << withdrawAmount << " withdrawn" << endl;
						}

					}

					else if (savingsDecision == 3) // Check Savings account balance
					{
						double balance = 0;

						cout << "Savings Account Balance" << endl;
						cout << "$" << savings.getSavingsBalance() << endl; // Retrieve Savings account balance
						cout << endl;
						cout << endl;
						cout << "Annual Savings Account Projection using 3.3% APR" << endl;

						double month1 = savings.computeInterest(1); // Month 1
						double month6 = savings.computeInterest(6);  // Month 6
						double month12 = savings.computeInterest(12); // Month 12

						cout << "Month 1: $" << month1 << endl;
						cout << "Month 6: $" << month6 << endl;
						cout << "Month 12: $" << month12 << endl;
					}

					else if (savingsDecision == 4) // Transfer money from Savings account to Checkings account
					{
						double transfer = 0; // Intialize transfer amount to zero

						cout << "Transfer money from Savings Account to Checkings Account" << endl;
						cout << "Please enter the amount you would like to transfer to Checkings" << endl;
						cin >> transfer;

						while (transfer <= 0) // Check that transfer amount is not negative
						{
							cout << "Transfer amount cannot be negative. Please enter a valid amount." << endl;
							cin >> transfer;
						}

						if (savings.transfer(transfer)) // Pass transfer amount via savings.transfer where transfer will be moved to a static transferAmount variable
						{
							checking.receiveTransfer(); // Trigger the checking account to accept transfer from static variable transferAmount
							cout << "Transaction Successful - $" << transfer << " transferred to Checkings" << endl;
						}
						else // If there is not money in the savings account for the transfer, display the message below
						{
							cout << "Insufficient Funds- Transaction Failed" << endl; 
						}
					}

					else
						running2 = false; // Inner loop set to false, now we exit to main menu
				}

			}

			else
			{
				running = false; // Outer loop set to false, exit program
			}

		}

		//-------------------------------------------USER ACCOUNT DETAIL UPDATE-------------------------------------------------------------------------
		// Main Function: Convert the Savings Balance (double) and Checkings Balance (double) to a string. Store the updated balances into their
		// respective vectors. Then create two new .dat files with the same name as the previous .dat files (checkingAccount.dat and savingAccount.dat)
		// and load each .dat file with their respective vectors.
		// 1) Retrieve updated Balances => convert Balances to string
		// 2) Change updated data in both vector files
		// 3) Create two new .dat files and fill them up with their respective vector files
		// 4) Close all object writing files
		// 5) Bid customer farewell
		//-----------------------------------------------------------------------------------------------------------------------------------------------

		double updatedChecking = 0; // updatedChecking holds the updated Checkings balance after all transactions are completed by user
		double updatedSavings = 0;  // updatedSavings holds the updated Savings balance after all transactions are completed by user

		updatedChecking = checking.getBalance(); // Set updatedChecking to the new Checkings balance
		updatedSavings = savings.getBalance();   // Set updatedSavings to the new Savings balance
		
		stringstream ss; // Create stringstream object to convert updatedChecking (double) to a string so it can be stored in a vector
		stringstream rs; // Create stringstream object to convert updatedSaving (double) to a string so it can be stored in a vector

		ss << updatedChecking << endl; // Input double to be converted to string

		string stringChecking = ss.str(); // Set the stringChecking (string type) to the updatedChecking string

		rs << updatedSavings << endl; // Input double to be converted to string
		
		string stringSavings = rs.str(); // Set stringSavings (string type) to the updatedSavings string


		for (unsigned int i = 0; i < userCheckings.size(); i++) // Sift through vector (Checkings) and search for userName
		{
			if (userName == userCheckings[i]) // If userName is found in vector continue to next step
			{
				userCheckings[i + 1] = stringChecking; // Update the element after the userName to the updated Checkings balance
			}
		}

		for (unsigned int i = 0; i < userSavings.size(); i++) // Sift through vector (Savings) and search for userName
		{
			if (userName == userSavings[i]) // If userName is found in vector continue to next step
			{
				userSavings[i + 1] = stringSavings; // Update the element after the userName to the updated Savings balance
			}
		}

		ofstream updateCheckingsFile; // Create two new object files for writing
		ofstream updateSavingsFile;
		
		updateCheckingsFile.open("checkingAccount.dat"); // Create a new .dat file with the same name as the previously created one
		updateSavingsFile.open("savingAccount.dat"); // Create a new .dat file with the same name as the previously created one


		while(updateCheckingsFile.is_open()) // Loop while file is open
		{
			for (unsigned int i = 0; i < userCheckings.size() - 1; i++) // Copy all vector contents into checkingAccount.dat
			{
				updateCheckingsFile << userCheckings[i] << endl;
			}

			updateCheckingsFile.close(); // Close object file
		}

		while (updateSavingsFile.is_open()) // Loop while file is open
		{
			for (unsigned int i = 0; i < userSavings.size() - 1; i++) // Copy all vector contents into savingAccount.dat
			{
				updateSavingsFile << userSavings[i] << endl;
			}

			updateSavingsFile.close(); // Close object file
		}

		cout << "Thank you for using our services " << userName << endl;
		cout << "We hope to see you again!" << endl;

	}
		system("pause");
		return 0;
}


bool verifyLogin(string &userName,cur_acct &checking, sav_acct &savings, vector<string>& userCheckings, vector<string>& userSavings)
{
	string userPassword;

	checking.setAccountType(1); // Set Account Type to Checking
	savings.setAccountType(2);  // Set Account Type to Savings

	checking.setAccountNum();   // Set account number for Checking Account
	savings.setAccountNum();    // Set account number for Savings Account

	bool accountFlag = false;
	bool passwordFlag = false;

	int option = 0; // User option

	cout << "Bank of C++" << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Login" << endl;
	cin >> option;

	if (option == 1) // USER CHOOSES TO CREATE NEW ACCOUNT
	{
		//--------------------------------CREATE USER PROFILE------------------------------------------------------------------------
		// Main Function: Create user profile
		// 1) Create two .dat files
		// 2) One .dat file is named AccountName.dat that stores the Account Holder's name.
		// 2) Second .dat file is named AccountPassword.dat that stores the Account Holder's password.
		//---------------------------------------------------------------------------------------------------------------------------

		ofstream accountFile; // Object for writing
		ofstream passwordFile; // Object for writing
		
		bool accountStatus = false;

		accountFile.open("AccountName.dat", std::fstream::app | std::ios_base::out); // Create dat file to hold user's account name
		passwordFile.open("AccountPassword.dat", std::fstream::app | std::ios_base::out); // Create dat file to hold user's password 

		while (accountStatus != true)
		{
			cout << "Create Account" << endl;
			cout << "Please enter a username: ";
			cin >> userName;							// Get user's name
			string checkName = userName;
			if (verifyuserName(checkName))
			{
				accountFile << userName << endl;			// Write user's name into the AccountName.dat file
				cout << "Please enter your password: ";
				cin >> userPassword;						// Get user's password
				passwordFile << userPassword << endl;		// Write user's password into the AccountPassword.dat file
				cout << "Account Creation Successful" << endl;
				cout << "Details" << endl;
				cout << "Username = " << userName << endl;
				cout << "Password = " << userPassword << endl;

				accountFile.close(); // Close the accountFile.dat
				passwordFile.close(); // Close the passwordFile.dat
				accountStatus = true;
			}

			else
			{
				cout << "Sorry username is already taken, please try again." << endl;
				cout << endl;
				accountStatus = false;
			}
		}
		//-----------------------------INITIALIZE USER'S BANK ACCOUNT-----------------------------------------------------------------
		// Main Function: Intialize user's Checkings account and user's Savings account
		// 1) Create two .dat files
		// 2) One .dat file named checkingAccount.dat holds => User's name & User's principal deposit into Checking account
		// 3) Second .dat file named savingAccount.dat holds => User's name & User's principal deposit into Savings account
		//----------------------------------------------------------------------------------------------------------------------------
		
		ofstream checkingAccount; // Create .dat file to hold account username and checking balance
		ofstream savingAccount; // Create .dat file to hold account username and savings balance

		checkingAccount.open("checkingAccount.dat", std::fstream::app|std::ios_base::out); // Create and open the checkingAccount.dat
		savingAccount.open("savingAccount.dat", std::fstream::app|std::ios_base::out); // Create and open the savingAccount.dat
		
		checkingAccount << userName << endl; // Write the userName into the checkingAccount.dat file
		savingAccount << userName << endl; // Write the userName into the savingAccount.dat file

		double checkingAmount = 0; // The principal amount the user wants to deposit into the checking account
		double savingsAmount = 0; // The principal amount the user wants to deposit into the savings account

		cout << "Account Intialization" << endl; // Account intialization ==> Intialize both checking and savings account
		cout << "Please enter the amount you would like to deposit into your checking account" << endl;
		cin >> checkingAmount;
		while (checkingAmount < 0) // Check to make sure checkingAmount is not below 0
		{
			cout << "Amount must be greater than zero." << endl;
			cin >> checkingAmount;
		}

		checkingAccount << checkingAmount << endl; // Write checking amount to the checkingAccount.dat file;

		cout << endl;

		cout << "Please enter the amount you would like to deposit into your savings account" << endl; // Principal deposit into savings account
		cin >> savingsAmount;
		while (savingsAmount < 0) // Check to make sure savingsAmount is not below 0
		{
			cout << "Amount must be greater than zero." << endl;
			cin >> savingsAmount;
		}

		savingAccount << savingsAmount << endl; // Write the principal amount to savingAccount.dat

		checkingAccount.close(); // Close the checkingAccount.dat file
		savingAccount.close();  // Close the savingsAccount.dat file
		
		//------------------------------CLOSE FILE STREAM OBJECTS-------------------------------------------------------------------------
		// Main Function: Close file stream objects and display disclaimer message to customer
		//--------------------------------------------------------------------------------------------------------------------------------

		cout << endl;
		cout << "DISCLAIMER: Balance in checking account must maintain a minimum balance of $100" << endl;
		cout << "or else a surcharge will be added to your account." << endl;
		cout << endl;
		cout << "Account is ready to use. Please exit and log back in." << endl;
		system("pause");
		exit(1);
	}

	if (option == 2) // USER CHOOSES TO LOGIN
	{
		//---------------------------------LOGIN VERIFICATION-------------------------------------------------------------------------------
		// Main Function: Verify user input credentials to confirm user is a memeber
		// 1) Create two file stream objects
		// 2) accountFile searches for user input name in AccountName.dat 
		// 3) passwordFile searches for user input password in AccountPassword.dat
		//----------------------------------------------------------------------------------------------------------------------------------

		ifstream accountFile; // Create filestream object to check for user's account name in AccountName.dat
		ifstream passwordFile; // Create filstream object to check for user's password in AccountPassword.dat

		accountFile.open("AccountName.dat"); // Open file holding the Account names
		passwordFile.open("AccountPassword.dat"); // Open file holding the Account passwords

		string temp;
		string user;	 // User input name
		string password; // User input password
		string line;

		cout << "Login Page" << endl;
		cout << "Enter username: ";
		cin >> user;
		cout << "Enter password: ";
		cin >> password;

		userName = user; // Set username to user

		if (accountFile.is_open()) // Search for user account name in dat file
		{
			while (getline(accountFile, temp))
			{
				line.append(temp);

				if (line.find(user) != string::npos) // If user name is found set accountFlag to true
				{
					accountFlag = true; // Set accountFlag to true
				}

			}
			accountFile.close(); // Close accountFile object
		}
		if (passwordFile.is_open()) // Search for user password in dat file
		{
			while (getline(passwordFile, temp))
			{
				line.append(temp);

				if (line.find(password) != string::npos) // If password is found set passwordFlag to true
				{
					passwordFlag = true; // Set passwordFlag to true
				}

			}
			passwordFile.close(); // Close passWord object
		}

	}
	
	//-----------------------------------RETRIEVE MEMBER'S BALANCE-------------------------------------------------------------------------------
	// ***IMPORTANT*** : This function only executes if both status flags (accountFlag and passwordFlag are set to true)
	// 
	// Main Function: Search for user name in .dat files and retrieve the corresponding balance per respective account type
	// 1) Create two filestream objects
	// 2) findChecking searches for user's name then retrieves the checking account balance
	// 3) findSavings searches for user's name then retrieves the savings account balance
	//--------------------------------------------------------------------------------------------------------------------------------------------

	if (accountFlag && passwordFlag) // If both accountFlag and passwordFlag are true then return true
	{
		string clientName = userName;
	
		ifstream findChecking; // Find the checking account balance for the user
		ifstream findSavings;  // Find the saving account balance for the user
		
		string userChecking;
		string userSaving;

		double retrievedChecking = 0; 
		double retrievedSavings = 0;

		findChecking.open("checkingAccount.dat"); // Open the .dat file holding the user's account name and checking account balance
		findSavings.open("savingAccount.dat"); // Open the .dat file holding the user's account name and savings account balance
		
		while (!findChecking.eof())	// Load all data from .dat to vector => This holds user name and checking balance
		{
			{
				findChecking >> userChecking;
				userCheckings.push_back(userChecking); 
			}
		}

		findChecking.close(); // Close findChecking object

		while (!findSavings.eof()) // Load all data from .dat to vector => This holds user name and savings balance
		{
			{
				findSavings >> userSaving;
				userSavings.push_back(userSaving);
			}
		}

		findSavings.close(); // Close findSavings object

		//----------------------------------------------------------------------------------------------------------------------------------------------------------------
		//	FUNCTION: Grab user information => Checking and Saving account balances
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------

		string userCheckingBalance; // Store user checking balance
		string userSavingsBalance; // Store user savings balance

		for (unsigned int i = 0; i < userCheckings.size(); i++) // Get checking balance for user
		{
			if (userName == userCheckings[i]) // If username is found retrieve element after userName and set the Checkings account to userCheckingsBalance
			{
				userCheckingBalance = userCheckings[i + 1]; 
			}
		}

		for (unsigned int i = 0; i < userSavings.size(); i++) // Get checking balance for user
		{
			if (userName == userSavings[i]) // If username is found retrieve element after userName and set the Savings account to userSavingsBalance 
			{
				userSavingsBalance = userSavings[i + 1];
			}
		}

		findSavings.close(); // Close findSavings object

		double checkingBalance = stod(userCheckingBalance); // Convert string(userCheckingBalance and userSavingsBalance) to double so it can be used by the objects
		double savingsBalance = stod(userSavingsBalance);

		savings.setBalance(savingsBalance); // Set savings balance using the double savingsBalance
		checking.setBalance(checkingBalance); // Set checkings balance using the double checkingsBalance

		remove("checkingAccount.dat"); // Erase the checkingAccount.dat file so it can be reinitialized later after the user exits from the system
		remove("savingAccount.dat"); // Erase the savingAccount.dat file so it can be reinitialized later after the user exits from the system

		return true; // Return true to main
	}
	else 
		return false; // Return false because credentials are bad or user doesn't exist in data files
	
}

bool verifyuserName(string checkName)
{
	ifstream existingUser;
	string temp;
	string line;
	bool userNameExists = true;

	existingUser.open("AccountName.dat");

	if (existingUser.is_open())
	{
		while (getline(existingUser, temp))
		{
			line.append(temp);

			if (line.find(checkName) != string::npos)
			{
				userNameExists = false;
			}

		}

	}
	existingUser.close();

	return userNameExists;
}