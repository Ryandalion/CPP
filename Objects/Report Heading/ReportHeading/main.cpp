#include <iostream>
#include <string>

#include "heading.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string company;
	string report;
	
	Heading c1;

	cout << "Please enter the company name: " << endl;
	getline(cin, company);

	cout << "Please enter the report name: " << endl;
	getline(cin, report);

	c1.setCompanyName(company);
	c1.setReportName(report);

	cout << "Normal Version:" << endl;
	cout << endl;
	c1.single();
	cout << endl;
	cout << endl;

	c1.stars();
	cout << endl;
	system("pause");
}