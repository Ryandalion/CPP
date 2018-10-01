#include "dateclass.h"
#include <string>

std::string months[12] = { "January","Feburary","March","April","May","June","July","August","September", "October", "November", "December" };

Date::Date()
{
	newDay = 1;
	newMonth = 1;
	newYear = 2001;
}

void Date::setDay(int day)
{
	newDay = day;
}

void Date::setYear(int year)
{
	newYear = year;
}

void Date::setMonth(int month)
{
	newMonth = month;
}

int Date::getDay() const
{
	return newDay;
}

int Date::getMonth() const
{
	return newMonth;
}

int Date::getYear() const
{
	return newYear;
}

void Date::slash()
{
	cout << newDay << "/" << newMonth << "/" << newYear;
}

void Date::word()
{
	cout << months[newMonth-1] << " " << newDay << ", " << newYear;
}

void Date::number()
{
	cout << newDay << " " << months[newMonth-1] << " " << newYear;
}

Date::~Date()
{

}


