#include <iostream>


class Inventory
{
public:
	Inventory();
	Inventory(int itemNum, int quant, double normalcost);
	~Inventory();

	void setItemNumber(int itemNum);
	void setQuantity(int quant);
	void setCost(int normalcost);
	void setTotalCost();
	
	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();


private:
	int itemNumber;
	int totalCost;
	int quantity;
	double cost;
};