#include "inventory.hpp"


Inventory::Inventory()
{
	itemNumber = 0;
	quantity = 0;
	cost = 0;
	totalCost = 0;
}

Inventory::Inventory(int itemNum, int quant, double normalcost)
{

	setItemNumber(itemNum);
	setQuantity(quant);
	setCost(normalcost);
	setTotalCost();
}

void Inventory::setItemNumber(int itemNum)
{
	itemNumber = itemNum;
}

void Inventory::setQuantity(int quant)
{
	quantity = quant;
}

void Inventory::setCost(int normalcost)
{
	cost = normalcost;
}

void Inventory::setTotalCost()
{
	totalCost = (quantity * cost);
}

int Inventory::getItemNumber()
{
	return itemNumber;
}

int Inventory::getQuantity()\
{
	return quantity;
}

double Inventory::getCost()
{
	return cost;
}

double Inventory::getTotalCost()
{
	return totalCost;
}

Inventory::~Inventory()
{

}