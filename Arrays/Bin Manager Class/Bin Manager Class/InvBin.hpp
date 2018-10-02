#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#ifndef INVBIN_H
#define INVBIN_H

class InvBin
{
public:
	InvBin();
	
	void setDescription(string); // Set the description for the bin
	string getDescription(); // Return the description of the bin
	void setQty(int q); // Set the quantity of the bin
	int getQty(); // Return the quantity of the bin

	~InvBin();

private:
	string description; // Item name
	int qty; // Item quantity
};

#endif