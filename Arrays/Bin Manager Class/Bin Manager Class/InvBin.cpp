#include "InvBin.hpp"

InvBin::InvBin()
{
	description = " ";
	qty = 0;
}

void InvBin::setDescription(string itemName) // Set description to item name that is passed
{
	description = itemName;
}

string InvBin::getDescription() // Return item name 
{
	return description;
}

void InvBin::setQty(int q) // Set quantity of item
{
	qty = q;
}

int InvBin::getQty() // Return quantity of item
{
	return qty;
}

InvBin::~InvBin()
{

}