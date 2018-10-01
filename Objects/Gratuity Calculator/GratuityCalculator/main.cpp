#include <iostream>
#include "tips.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double cost;
	int choice;
	double tipRate;
	double rate;
	bool running = true;
	

	cout << "Welcome to the Gratuity Calculator!" << endl;
	cout << "Please enter the following information to calculate your total" << endl;
	while (running != false)
	{
		cout << "Enter the tax rate: " << endl;
		cin >> rate;
		Tips customer1(rate);
		cout << "Enter the cost: " << endl;
		cin >> cost;
		cout << "Enter the tip percentage: " << endl;
		cin >> tipRate;
		cout << "Here is your tip on the bill: " << customer1.computeTip(cost, tipRate) << endl;


		cout << "Would you like to enter another amount?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;
		if (choice == 1)
		{
			running = true;
		}
		else
		{
			running = false;
		}
	}
}