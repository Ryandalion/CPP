#include "payRoll.hpp"

payRoll::payRoll()
{
	hourlyPay = 0;
	hoursWorked = 0;
}

void payRoll::setWage(double pay)
{
	hourlyPay = pay;
}

void payRoll::setHours(double hours)
{
	hoursWorked = hours;
}

double payRoll::grossPay()
{
	double wage = 0;

	wage = (hourlyPay * hoursWorked);

	return wage;
}

payRoll::~payRoll()
{

}