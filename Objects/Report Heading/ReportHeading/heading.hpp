#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;

#ifndef HEADING_H
#define HEADING_H

class Heading
{
public:
	Heading();
	~Heading();
	
	void setCompanyName(string company);
	void setReportName(string report);

	void single();
	void stars();

private:
	string cname;	//Company Name
	string rname;	//Report Name
};




#endif