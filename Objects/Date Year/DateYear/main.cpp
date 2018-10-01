#include <iostream>
#include <string>
#include "dateclass.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int day,
		month,
		year;

	int minday = 0;
	int minmonth = 1;
	int minyear = 0;
	
		cout << "Enter the day: " << endl;
		cin >> day;
		cout << "Enter the month: " << endl;
		cin >> month;
		cout << "Enter the year: " << endl;
		cin >> year;
	
		Date thisyear;

		thisyear.setDay(day);
		thisyear.setMonth(month);
		thisyear.setYear(year);

	cout << "Here are the dates listed in various forms: " << endl;
	thisyear.slash();
	cout << endl;
	thisyear.word();
	cout << endl;
	thisyear.number();
	cout << endl;

	system("pause");
}