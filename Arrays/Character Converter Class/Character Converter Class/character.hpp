#include <iostream>
#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

using std::string;
using std::cout;
using std::cin;
using std::endl;

class CharConverter
{
public:
	CharConverter();
	string uppercase(string);
	string properWords(string);
	~CharConverter();
private:
	string convertedString;
	string uppercaseString;
};

#endif