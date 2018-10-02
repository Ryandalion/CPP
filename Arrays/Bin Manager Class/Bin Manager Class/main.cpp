#include <iostream>
#include <string>

#include "BinManager.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int size = 9; // Set the number of items that will be used
	string s[] = { "regular pliers", "n. nose pliers", "screwdriver", "p. head screw driver", "wrench-large", "wrench-small", "drill", "cordless drill", "handsaw" }; // Initialize string array to item names
	int q[] = { 25, 5, 25, 6, 7, 18, 51, 16, 12 }; // Intialize quantity array to the quantity of each item

	BinManager manager(size, s, q); // Call overloaded BinManager constructor to intialize bins

	bool running = true; // Bool to determine if user wants to continue using application
	int option = 0; // User decision for menu choice

	int itemNumber; // The item number the user wishes to add/remove
	int addQty; // The number of items the user wishes to add
	int removalQty; // The number of itesm the user wishes to remove
	
	

	cout << "Warehouse Bin Manager" << endl;
	cout << endl;

	while (running != false) // While loop to allow user to continue using application
	{
		cout << "Current Inventory" << endl;
		cout << endl;
		for (int i = 0; i < size; i++) // Print out current invetory so user can see item names and item quantity
		{
			cout << i+ 1 << ". " << "Item Name: " << manager.getDescription(i) << endl;
			cout << "   Item Quantity: " << manager.getQuantity(i) << endl;
			cout << endl;
		}
		cout << endl;
		cout << "Please select an action" << endl;
		cout << "1. Add items to a bin" << endl;
		cout << "2. Remove items from a bin" << endl;
		cout << "3. Display number of items in each bin" << endl;
		cout << "4. Exit Program" << endl;
		cin >> option;
		
		while (option > 4 || option < 0) // Input validation; If user does not select a valid input error message appears
		{
			cout << "Invalid option. Please try again." << endl;
			cin >> option;
		}
		
		if (option == 1) // Add items and call a bool function
		{
			cout << "Which item would you like to add? " << endl;
			cin >> itemNumber;
			cout << "How many items would you like to add?" << endl;
			cin >> addQty;
			if (manager.addParts(itemNumber, addQty)) // Add item; User enters the item they wish to add and the quantity they wish to add
			{
				cout << "Item successfully added" << endl; // If quantity update is successful, print success message
			
			}
			else
			{
				cout << "Item could not be added" << endl; // Else print message that addition could not be executed
			
			}
		}

		if (option == 2) // Remove items using a bool function
		{
			cout << "Which item would you like to remove? " << endl;
			cin >> itemNumber;
			cout << "How many items would you like to remove?" << endl;
			cin >> removalQty;
			if ((manager.removeParts(itemNumber, removalQty))) // Remove item; User enters the item they wish to remove and the quantity they wish to remvoe
			{
				cout << "Item successfully removed" << endl; // If removal successful print item has been removed
			}
			else
			{
				cout << "Item could not be removed" << endl; // If removal is unsuccessful print error message
			}

		}

		if (option == 3) // Print current inventory
		{
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << ". " << "Item Name: " << manager.getDescription(i) << endl;
				cout << "   Item Quantity: " << manager.getQuantity(i) << endl;
				cout << endl;
			}
		}
		
		if (option == 4) // Set bool to false and exit while loop
		{
			running = false;
		}
	}

	system("pause");
}