#include <iostream>

using std::cout;
using std::endl;

#ifndef TIPS_H
#define TIPS_H


class Tips
{
public:
	Tips();
	Tips(double rate);
	~Tips();

	double computeTip(double bill, double tipRate);

private:
	double taxRate;
	double totalCost;
};

#endif