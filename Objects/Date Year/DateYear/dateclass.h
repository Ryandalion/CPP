#include <iostream>
#include <string>

#ifndef dateclass_H
#define dateclass_H

using std::cout;
using std::cin;
using std::endl;

class Date 
{
public:
	Date();
	~Date();
	
	void slash();
	void word();
	void number();

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

private:
	int newMonth;
	int newDay;
	int newYear;
};


#endif
