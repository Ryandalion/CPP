#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;

const int number = 20;

struct sodaType
{
	string sodaName; // Name of soda
	double sodaCost; // Cost of soda
	double sodaQuantity; // Number of soda available
};

class sodaMachine
{
public:

	sodaMachine();
	void displayChoices(); // Display a menu of drink names and prices
	void buyDrink(int selection, double& balance); // Handles a sale; @param is user's requested soda
	~sodaMachine(); // Destructor and also displays the final day sales statistics

private:

	sodaType soda[5] = { {"Cola", 1.00, number},{"Root Beer", 1.00, number},{"Orange Soda", 1.00,number},{"Grape Soda", 1.00, number},{"Bottled Water", 1.50, number} };
	void inputMoney(int selection, double& balance); // Accept, validate, and return to buyDrink the amount of money input
	void dailyReport(); // Daily report will be used by the destructor and report how many of each drink type remain and how much money was collected
	double sales = 0;

};