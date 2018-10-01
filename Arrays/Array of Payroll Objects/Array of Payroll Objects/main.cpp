#include <iostream>
#include <fstream>
#include <string>

#include "payRoll.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::getline;
using std::string;

int main()
{
	payRoll employee[7]; // 7 Employee Objects
	ifstream employeeData; // Input File stream object

	double hours;	// Hours
	double wage;	// Wage
	double totalWage; // Total Wage ==> Employee # (hours * wage)
	string fileName;  // File name that is input by user

	cout << "Payroll Entry Form" << endl;
	cout << "This system can only calculate the wage for 7 employees" << endl;
	cout << "Enter the filename that contains the employee's data (remember to include extension tag)" << endl;
	cin >> fileName;
	cout << endl;
	employeeData.open(fileName); // Open file name input by user
	for(int i = 0; i < 7; i++)
	{
		employeeData >> hours; // Set data to hours
		employee[i].setHours(hours); // Pass hours to employee object

		employeeData >> wage; // Set hourly pay to wage
		employee[i].setWage(wage); // Pass wage to employee object
	}

	employeeData.close(); // Close reading file

	cout << "Total Earnings Per Employee" << endl;
	for (int i = 0; i < 7; i++)
	{
		totalWage = employee[i].grossPay(); // Calculate gross pay per object
		cout << "Employee #" << i + 1 << " earned: $" << totalWage << endl;
		totalWage = 0; // Reset totalWage for next employee
	}

	cout << endl;
	system("pause");

}
