#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct MonthlyBudget
{
	MonthlyBudget();
	MonthlyBudget(double house, double util, double expense, double transport, double food, double medical, double insur, double entertain, double cloth, double misc);

	double housing;
	double utilities;
	double householdexpenses;
	double transportation;
	double foodcost;
	double medicalcost;
	double insurance;
	double entertainment;
	double clothing;
	double random;

	void calculateTotal();
	double total;
};

MonthlyBudget::MonthlyBudget()
{

}

MonthlyBudget::MonthlyBudget(double house, double util, double expense, double transport, double food, double medical, double insur, double entertain, double cloth, double misc)
{
	housing = house;
	utilities = util;
	householdexpenses = expense;
	transportation = transport;
	foodcost = food;
	medicalcost = medical;
	insurance = insur;
	entertainment = entertain;
	clothing = cloth;
	random = misc;
}

void MonthlyBudget::calculateTotal()
{
	total = housing + utilities + householdexpenses + transportation + foodcost + medicalcost + insurance + entertainment + clothing + random;
}


void displayBudget(MonthlyBudget budget);
void BudgetChange(MonthlyBudget budget, MonthlyBudget budget2);

int main()
{
	MonthlyBudget last, current;

	last.housing = 500;
	last.utilities = 150;
	last.householdexpenses = 65;
	last.transportation = 50;
	last.foodcost = 50;
	last.medicalcost = 250;
	last.insurance = 30;
	last.entertainment = 150;
	last.clothing = 75;
	last.random = 50;

	
	cout << "Last Month's Budget" << endl;
	displayBudget(last);
	last.calculateTotal();
	cout << "Last Month's Total Budget: " << last.total << endl;

	cout << endl;
	cout << "Please enter this month's budget" << endl;
	cout << "Housing: " << endl;
	cin >> current.housing;
	cout << "Utilities: " << endl;
	cin >> current.utilities;
	cout << "Household Expenses: "<< endl;
	cin >> current.householdexpenses;
	cout << "Transportation: "<< endl;
	cin >> current.transportation;
	cout << "Food Cost: "<< endl;
	cin >> current.foodcost;
	cout << "Medical Expense: " << endl;
	cin >> current.medicalcost;
	cout << "Insurance: "<< endl;
	cin >> current.insurance;
	cout << "Entertainment: "<< endl;
	cin >> current.entertainment;
	cout << "Clothing: "<< endl;
	cin >> current.clothing;
	cout << "Misc. Expenses: " << endl;
	cin >> current.random;
	current.calculateTotal();
	
	cout << endl;
	cout << "This Month's Budget" << endl;
	displayBudget(current);
	cout << "This Month's Total Budget: " << current.total << endl;

	BudgetChange(last, current);

	cout << endl;
	cout << "The total difference between the two budgets is $" << (last.total - current.total) << endl;
	system("pause");

}

void displayBudget(MonthlyBudget budget)
{
	cout << "Housing: " << budget.housing << endl;
	cout << "Utilities: " << budget.utilities << endl;
	cout << "Household Expenses: " << budget.householdexpenses << endl;
	cout << "Transportation: " << budget.transportation << endl;
	cout << "Food Cost: " << budget.foodcost << endl;
	cout << "Medical Expense: " << budget.medicalcost << endl;
	cout << "Insurance: " << budget.insurance << endl;
	cout << "Entertainment: " << budget.entertainment << endl;
	cout << "Clothing: " << budget.clothing << endl;
	cout << "Misc. Expenses: " << budget.random << endl;
}

void BudgetChange(MonthlyBudget last, MonthlyBudget current)
{
	cout << endl;
	cout << "Changes in budget" << endl;
	cout << "Housing: " << last.housing - current.housing << endl;
	cout << "Utilities: " << last.utilities - current.utilities << endl;
	cout << "Household Expenses: " << last.utilities - current.utilities << endl;
	cout << "Transportation: " << last.utilities - current.utilities << endl;
	cout << "Food Cost: " << last.utilities - current.utilities << endl;
	cout << "Medical Expense: " << last.utilities - current.utilities << endl;
	cout << "Insurance: " << last.utilities - current.utilities << endl;
	cout << "Entertainment: " << last.utilities - current.utilities << endl;
	cout << "Clothing: " << last.utilities - current.utilities << endl;
	cout << "Misc. Expenses: " << last.utilities - current.utilities << endl;
}
