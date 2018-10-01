#include <iostream>

#ifndef PAYROLL_H
#define PAYROLL_H

class payRoll 
{
public:
	payRoll();
	void setWage(double pay);
	void setHours(double wage);
	double grossPay();
	~payRoll();

private:
	double hourlyPay;
	double hoursWorked;
};


#endif