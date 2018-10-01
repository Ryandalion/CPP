#include <iostream>
#include <string>

#include "inventory.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int itemnum;
	int quantity;
	int useroption;
	double cost;

	cout << "Warehouse DataBase" << endl;

	{
		cout << "Enter the item number: " << endl;
		cin >> itemnum;
		cout << "Enter the quantity: " << endl;
		cin >> quantity;
		cout << "Enter the wholesale cost per unit: " << endl;
		cin >> cost;
		while (itemnum < 0 || quantity < 0 || cost < 0)
		{
			cout << "Please enter valid inputs" << endl;
			cout << "Enter the item number: " << endl;
			cin >> itemnum;
			cout << "Enter the quantity: " << endl;
			cin >> quantity;
			cout << "Enter the wholesale cost per unit: " << endl;
			cin >> cost;
		}
		cout << endl;
		cout << "VERIFICATION: ITEM DETAILS" << endl;
		Inventory stock1(itemnum, quantity, cost);
		cout << "Item Number: " << stock1.getItemNumber() << endl;
		cout << "Quantity: " << stock1.getQuantity() << endl;
		cout << "Cost: " << stock1.getCost() << endl;
		cout << "Total Cost: $" << stock1.getTotalCost() << endl;
		system("pause");
	}
}