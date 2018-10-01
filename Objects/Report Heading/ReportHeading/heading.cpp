#include "heading.hpp"

Heading::Heading()
{
	cname = "ABC Industries";
	rname = "Report";
}

void Heading::setCompanyName(string company)
{
	cname = company;
}

void Heading::setReportName(string report)
{
	rname = report;
}

void Heading::single()
{
	cout << cname << " " << rname;
}

void Heading::stars()
{
	for (int i = 0; i <= 30; i++)
		cout << "*";
	cout << endl;
	cout << setw(20);
	cout << cname << endl;
	cout << setw(20);
	cout << rname << endl;
	for (int i = 0; i <= 30; i++)
		cout << "*";
}

Heading::~Heading()
{

}