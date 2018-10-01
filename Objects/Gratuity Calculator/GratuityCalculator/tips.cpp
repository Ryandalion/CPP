#include "tips.hpp"

Tips::Tips(double rate)
{
	if (rate <= 0)
	{
		taxRate = .065;
	}
	else
	{
		taxRate = (rate/100);
	}
}


double Tips::computeTip(double bill, double tipRate)
{
	tipRate = (tipRate / 100);
	totalCost = (bill * tipRate) - (bill * taxRate);
	return totalCost;
}

Tips::~Tips()
{

}